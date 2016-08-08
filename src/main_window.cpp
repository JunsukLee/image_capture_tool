/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include "main_window.hpp"

#include <QtGui>
#include <QMessageBox>
#include <iostream>



/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace image_capture_tool {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application
    ReadSettings();
    setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    ui.StopButton->setDisabled(true);   //초기 Stop버튼 설정
    ui.tab_Image->setDisabled(true);
    ui.tab_Video->setDisabled(true);    
    ui.lineEdit_Path->setText(QDir::homePath()+"/data/Image");
    ui.lineEdit_Path_Video->setText(QDir::homePath()+"/data/Video");





	/*********************
	** Logging
	**********************/
//    ui.view_logging->setModel(qnode.loggingModel());
//    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    QObject::connect(&qnode, SIGNAL(mainwindowUpdated()), this, SLOT(updateMainWindow()));

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
        if ( !qnode.init(getRosTopic()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
                   ui.line_edit_host->text().toStdString(),getRosTopic()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
            ui.tab_Image->setEnabled(true);
            ui.tab_Video->setEnabled(true);

		}
    }
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
//        ui.view_logging->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "image_capture_tool");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}




void MainWindow::on_RecordButton_clicked(){
    ui.OffButton->setStyleSheet("background-color: red; border-radius: 5px;");
    ui.OffButton->setText("On");
    ui.RecordButton->setDisabled(true);
    ui.StopButton->setEnabled(true);

    std::string date = ui.lineEdit_Date_Video->text().toStdString();
    std::string description = ui.lineEdit_Description_Video->text().toStdString();
    std::string id;
    if(0<=ui.spinBox_ID_Video->value()&& ui.spinBox_ID->value()<10) id = "000"+ui.spinBox_ID_Video->text().toStdString();
    else if(10<=ui.spinBox_ID_Video->value()&& ui.spinBox_ID->value()<100) id = "00"+ui.spinBox_ID_Video->text().toStdString();
    else if(100<=ui.spinBox_ID_Video->value()&& ui.spinBox_ID->value()<1000) id = "0"+ui.spinBox_ID_Video->text().toStdString();
    else id = ui.spinBox_ID_Video->text().toStdString();

    std::string path = ui.lineEdit_Path_Video->text().toStdString()+"/"+date+"_"+description;
    std::string filename = id +".avi";

    createFile(ui.lineEdit_Path_Video->text()+"/"+ui.lineEdit_Date_Video->text()+"_"+ui.lineEdit_Description_Video->text());
    if(QFile::exists(ui.lineEdit_Path->text()+"/"+ui.lineEdit_Date->text()+"_"+ui.lineEdit_Description->text()+"/"+ui.spinBox_ID->text()+".png")) QMessageBox::information(this,"Error","This file already exists");
    else if(!QFile::exists(ui.lineEdit_Path->text()+"/"+ui.lineEdit_Date->text()+"_"+ui.lineEdit_Description->text()+"/"+ui.spinBox_ID->text()+".png"))
    {
    qnode.record(ui.doubleSpinBox_fps->value(), path, filename);
    }
}
void MainWindow::updateMainWindow()
{
    cv::Mat image = qnode.getInputImage();
    cv::Mat rgb_image;
    cv::cvtColor(image, rgb_image, CV_BGR2RGB);
    //이미지 출력
    QImage qimage = QImage(rgb_image.data, rgb_image.cols, rgb_image.rows, rgb_image.step, QImage::Format_RGB888);
    QPixmap buf = QPixmap::fromImage(qimage);
//
    ui.label_main->setPixmap(buf);
    if(buf.width()>ui.label_main->size().width())
    {ui.label_main->resize(ui.label_main->size().width(),buf.height()*ui.label_main->size().width()/buf.width());}
    else
    ui.label_main->resize(buf.width(),buf.height());

    ui.label_main->setScaledContents(true);
}

void MainWindow::on_StopButton_clicked(){
    ui.OffButton->setText("Off");
    ui.OffButton->setAutoFillBackground(false);
    ui.OffButton->setStyleSheet("");
    ui.OffButton->update();

    ui.StopButton->setDisabled(true);
    ui.RecordButton->setEnabled(true);
    qnode.stopRecord();
    ui.spinBox_ID->stepUp();
}

void MainWindow::on_PathButton_clicked(){
    QUrl url = QFileDialog::getExistingDirectory();     //FileDialog 열어서 디렉토리설정
    ui.lineEdit_Path->setText(url.toString());          //File path표시

}

void MainWindow::on_CaptureButton_clicked(){

    qnode.capture();
    cv::Mat image = qnode.getCapturedImage();
    cv::Mat rgb_image;
    cv::cvtColor(image, rgb_image, CV_BGR2RGB);
    QImage qimage = QImage(rgb_image.data, rgb_image.cols, rgb_image.rows, rgb_image.step, QImage::Format_RGB888);
    QPixmap buf = QPixmap::fromImage(qimage);
    ui.label_caputred->setPixmap(buf);
    ui.label_caputred->setScaledContents(true);
}


void MainWindow::on_SaveButton_clicked()
{
    if(qnode.isCaptured())
    {

        std::string date = ui.lineEdit_Date->text().toStdString();
        std::string description = ui.lineEdit_Description->text().toStdString();
        std::string id;
        if(0<=ui.spinBox_ID->value() && ui.spinBox_ID->value()<10) id = "000"+ui.spinBox_ID->text().toStdString();
        else if(10<=ui.spinBox_ID->value()&& ui.spinBox_ID->value()<100) id = "00"+ui.spinBox_ID->text().toStdString();
        else if(100<=ui.spinBox_ID->value()&& ui.spinBox_ID->value()<1000) id = "0"+ui.spinBox_ID->text().toStdString();
        else id = ui.spinBox_ID->text().toStdString();

        std::string path = ui.lineEdit_Path->text().toStdString()+"/"+date+"_"+description;
        std::string filename = id +".png";

        createFile(ui.lineEdit_Path->text()+"/"+ui.lineEdit_Date->text()+"_"+ui.lineEdit_Description->text());

        if(QFile::exists(ui.lineEdit_Path->text()+"/"+ui.lineEdit_Date->text()+"_"+ui.lineEdit_Description->text()+"/"+ui.spinBox_ID->text()+".png")) QMessageBox::information(this,"Error","This file already exists");
        else if(!QFile::exists(ui.lineEdit_Path->text()+"/"+ui.lineEdit_Date->text()+"_"+ui.lineEdit_Description->text()+"/"+ui.spinBox_ID->text()+".png"))
        {
            qnode.saveCapturedImage(path, filename);
            ui.label_caputred->clear();
            ui.spinBox_ID->stepUp();
        }

    }
    else
        std::cerr << "[ERROR] : Input Image was not captured." << std::endl;
}

void MainWindow::on_PathButton_Video_clicked(){
    QUrl url = QFileDialog::getExistingDirectory();     //FileDialog 열어서 디렉토리설정
    ui.lineEdit_Path_Video->setText(url.toString());          //File path표시
}


void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "image_capture_tool");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::createFile(QString FilePath)
{
    QDir dir = QDir::root();
    dir.mkpath(FilePath);
}

std::string MainWindow::getRosTopic()
{
    return ui.line_edit_topic->text().toStdString();

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

}  // namespace image_capture_tool


