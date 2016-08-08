/**
 * @file /include/image_capture_tool/main_window.hpp
 *
 * @brief Qt based gui for image_capture_tool.
 *
 * @date November 2010
 **/
#ifndef image_capture_tool_MAIN_WINDOW_H
#define image_capture_tool_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "../../../build/image_capture_tool/ui_main_window.h"
#include "qnode.hpp"



/*****************************************************************************
** Namespace
*****************************************************************************/

namespace image_capture_tool {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();



public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically
    void on_PathButton_clicked();
    void on_RecordButton_clicked();
    void on_StopButton_clicked();
    void on_PathButton_Video_clicked();
    void on_CaptureButton_clicked();
    void on_SaveButton_clicked();
    void updateMainWindow();
//    void convertMat2QImage(const cv::Mat& _image, QImage& _qimage, QImage::Format _format);

private:
	Ui::MainWindowDesign ui;
    QNode qnode;
    std::string getRosTopic();
    void createFile(QString FilePath);

};

}  // namespace image_capture_tool

#endif // image_capture_tool_MAIN_WINDOW_H
