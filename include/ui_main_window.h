/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QFrame *frame_2;
    QLabel *label_main;
    QTabWidget *tab_manager;
    QWidget *tab_status;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_edit_master;
    QLabel *label_2;
    QLineEdit *line_edit_host;
    QLabel *label_3;
    QLineEdit *line_edit_topic;
    QCheckBox *checkbox_use_environment;
    QCheckBox *checkbox_remember_settings;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_connect;
    QSpacerItem *verticalSpacer_3;
    QPushButton *quit_button;
    QWidget *tab_Image;
    QLabel *CapturedImage;
    QGraphicsView *CapturedView;
    QLineEdit *lineEdit_Path;
    QPushButton *PathButton;
    QPushButton *CaptureButton;
    QLineEdit *lineEdit_Date;
    QPushButton *SaveButton;
    QLineEdit *lineEdit_Description;
    QLabel *label_Date;
    QLabel *label_dash;
    QLabel *label_Description;
    QLabel *label_dash2;
    QSpinBox *spinBox_ID;
    QLabel *label_ID;
    QLabel *label_png;
    QLabel *label_caputred;
    QWidget *tab_Video;
    QPushButton *PathButton_Video;
    QLineEdit *lineEdit_Path_Video;
    QPushButton *RecordButton;
    QPushButton *StopButton;
    QLabel *label_avi;
    QLineEdit *lineEdit_Description_Video;
    QLabel *label_Description_Video;
    QLabel *label_dash2_2;
    QLabel *label_dash_Video;
    QLineEdit *lineEdit_Date_Video;
    QSpinBox *spinBox_ID_Video;
    QLabel *label_Date_Video;
    QLabel *label_ID_Video;
    QPushButton *SaveButton_Video;
    QPushButton *OffButton;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(988, 738);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_main = new QLabel(frame_2);
        label_main->setObjectName(QString::fromUtf8("label_main"));
        label_main->setGeometry(QRect(30, 30, 381, 601));

        hboxLayout->addWidget(frame_2);

        tab_manager = new QTabWidget(centralwidget);
        tab_manager->setObjectName(QString::fromUtf8("tab_manager"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab_manager->sizePolicy().hasHeightForWidth());
        tab_manager->setSizePolicy(sizePolicy);
        tab_manager->setMinimumSize(QSize(100, 0));
        tab_manager->setLocale(QLocale(QLocale::English, QLocale::Australia));
        tab_status = new QWidget();
        tab_status->setObjectName(QString::fromUtf8("tab_status"));
        verticalLayout_2 = new QVBoxLayout(tab_status);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_12 = new QGroupBox(tab_status);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(groupBox_12);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame = new QFrame(groupBox_12);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_edit_master = new QLineEdit(groupBox);
        line_edit_master->setObjectName(QString::fromUtf8("line_edit_master"));

        gridLayout->addWidget(line_edit_master, 1, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        line_edit_host = new QLineEdit(groupBox);
        line_edit_host->setObjectName(QString::fromUtf8("line_edit_host"));

        gridLayout->addWidget(line_edit_host, 3, 0, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        line_edit_topic = new QLineEdit(groupBox);
        line_edit_topic->setObjectName(QString::fromUtf8("line_edit_topic"));
        line_edit_topic->setEnabled(false);

        gridLayout->addWidget(line_edit_topic, 5, 0, 1, 2);

        checkbox_use_environment = new QCheckBox(groupBox);
        checkbox_use_environment->setObjectName(QString::fromUtf8("checkbox_use_environment"));
        checkbox_use_environment->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_use_environment, 7, 0, 1, 2);

        checkbox_remember_settings = new QCheckBox(groupBox);
        checkbox_remember_settings->setObjectName(QString::fromUtf8("checkbox_remember_settings"));
        checkbox_remember_settings->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_remember_settings, 8, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(170, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 9, 0, 1, 1);

        button_connect = new QPushButton(groupBox);
        button_connect->setObjectName(QString::fromUtf8("button_connect"));
        button_connect->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(button_connect, 9, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 233, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        quit_button = new QPushButton(frame);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        sizePolicy3.setHeightForWidth(quit_button->sizePolicy().hasHeightForWidth());
        quit_button->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(quit_button);


        gridLayout_3->addWidget(frame, 0, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_12);

        tab_manager->addTab(tab_status, QString());
        tab_Image = new QWidget();
        tab_Image->setObjectName(QString::fromUtf8("tab_Image"));
        CapturedImage = new QLabel(tab_Image);
        CapturedImage->setObjectName(QString::fromUtf8("CapturedImage"));
        CapturedImage->setGeometry(QRect(10, 10, 311, 211));
        CapturedView = new QGraphicsView(tab_Image);
        CapturedView->setObjectName(QString::fromUtf8("CapturedView"));
        CapturedView->setGeometry(QRect(10, 60, 331, 281));
        lineEdit_Path = new QLineEdit(tab_Image);
        lineEdit_Path->setObjectName(QString::fromUtf8("lineEdit_Path"));
        lineEdit_Path->setGeometry(QRect(10, 20, 281, 31));
        PathButton = new QPushButton(tab_Image);
        PathButton->setObjectName(QString::fromUtf8("PathButton"));
        PathButton->setGeometry(QRect(300, 20, 41, 31));
        CaptureButton = new QPushButton(tab_Image);
        CaptureButton->setObjectName(QString::fromUtf8("CaptureButton"));
        CaptureButton->setGeometry(QRect(10, 460, 331, 31));
        lineEdit_Date = new QLineEdit(tab_Image);
        lineEdit_Date->setObjectName(QString::fromUtf8("lineEdit_Date"));
        lineEdit_Date->setGeometry(QRect(10, 390, 61, 27));
        SaveButton = new QPushButton(tab_Image);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(10, 510, 331, 31));
        lineEdit_Description = new QLineEdit(tab_Image);
        lineEdit_Description->setObjectName(QString::fromUtf8("lineEdit_Description"));
        lineEdit_Description->setGeometry(QRect(97, 390, 121, 27));
        label_Date = new QLabel(tab_Image);
        label_Date->setObjectName(QString::fromUtf8("label_Date"));
        label_Date->setGeometry(QRect(9, 419, 60, 17));
        label_dash = new QLabel(tab_Image);
        label_dash->setObjectName(QString::fromUtf8("label_dash"));
        label_dash->setGeometry(QRect(76, 398, 21, 17));
        label_Description = new QLabel(tab_Image);
        label_Description->setObjectName(QString::fromUtf8("label_Description"));
        label_Description->setGeometry(QRect(121, 420, 81, 17));
        label_dash2 = new QLabel(tab_Image);
        label_dash2->setObjectName(QString::fromUtf8("label_dash2"));
        label_dash2->setGeometry(QRect(224, 396, 21, 17));
        spinBox_ID = new QSpinBox(tab_Image);
        spinBox_ID->setObjectName(QString::fromUtf8("spinBox_ID"));
        spinBox_ID->setGeometry(QRect(246, 390, 61, 27));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(spinBox_ID->sizePolicy().hasHeightForWidth());
        spinBox_ID->setSizePolicy(sizePolicy4);
        spinBox_ID->setMaximum(9999);
        label_ID = new QLabel(tab_Image);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));
        label_ID->setGeometry(QRect(270, 420, 21, 17));
        label_png = new QLabel(tab_Image);
        label_png->setObjectName(QString::fromUtf8("label_png"));
        label_png->setGeometry(QRect(314, 397, 31, 17));
        label_caputred = new QLabel(tab_Image);
        label_caputred->setObjectName(QString::fromUtf8("label_caputred"));
        label_caputred->setGeometry(QRect(20, 70, 311, 261));
        tab_manager->addTab(tab_Image, QString());
        tab_Video = new QWidget();
        tab_Video->setObjectName(QString::fromUtf8("tab_Video"));
        PathButton_Video = new QPushButton(tab_Video);
        PathButton_Video->setObjectName(QString::fromUtf8("PathButton_Video"));
        PathButton_Video->setGeometry(QRect(300, 20, 41, 31));
        lineEdit_Path_Video = new QLineEdit(tab_Video);
        lineEdit_Path_Video->setObjectName(QString::fromUtf8("lineEdit_Path_Video"));
        lineEdit_Path_Video->setGeometry(QRect(10, 20, 281, 31));
        RecordButton = new QPushButton(tab_Video);
        RecordButton->setObjectName(QString::fromUtf8("RecordButton"));
        RecordButton->setGeometry(QRect(20, 160, 111, 31));
        StopButton = new QPushButton(tab_Video);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setGeometry(QRect(140, 160, 111, 31));
        label_avi = new QLabel(tab_Video);
        label_avi->setObjectName(QString::fromUtf8("label_avi"));
        label_avi->setGeometry(QRect(315, 218, 31, 17));
        lineEdit_Description_Video = new QLineEdit(tab_Video);
        lineEdit_Description_Video->setObjectName(QString::fromUtf8("lineEdit_Description_Video"));
        lineEdit_Description_Video->setGeometry(QRect(98, 211, 121, 27));
        label_Description_Video = new QLabel(tab_Video);
        label_Description_Video->setObjectName(QString::fromUtf8("label_Description_Video"));
        label_Description_Video->setGeometry(QRect(122, 241, 81, 17));
        label_dash2_2 = new QLabel(tab_Video);
        label_dash2_2->setObjectName(QString::fromUtf8("label_dash2_2"));
        label_dash2_2->setGeometry(QRect(225, 217, 21, 17));
        label_dash_Video = new QLabel(tab_Video);
        label_dash_Video->setObjectName(QString::fromUtf8("label_dash_Video"));
        label_dash_Video->setGeometry(QRect(77, 219, 21, 17));
        lineEdit_Date_Video = new QLineEdit(tab_Video);
        lineEdit_Date_Video->setObjectName(QString::fromUtf8("lineEdit_Date_Video"));
        lineEdit_Date_Video->setGeometry(QRect(11, 211, 61, 27));
        spinBox_ID_Video = new QSpinBox(tab_Video);
        spinBox_ID_Video->setObjectName(QString::fromUtf8("spinBox_ID_Video"));
        spinBox_ID_Video->setGeometry(QRect(247, 211, 61, 27));
        sizePolicy4.setHeightForWidth(spinBox_ID_Video->sizePolicy().hasHeightForWidth());
        spinBox_ID_Video->setSizePolicy(sizePolicy4);
        spinBox_ID_Video->setMaximum(9999);
        label_Date_Video = new QLabel(tab_Video);
        label_Date_Video->setObjectName(QString::fromUtf8("label_Date_Video"));
        label_Date_Video->setGeometry(QRect(10, 240, 60, 17));
        label_ID_Video = new QLabel(tab_Video);
        label_ID_Video->setObjectName(QString::fromUtf8("label_ID_Video"));
        label_ID_Video->setGeometry(QRect(271, 241, 21, 17));
        SaveButton_Video = new QPushButton(tab_Video);
        SaveButton_Video->setObjectName(QString::fromUtf8("SaveButton_Video"));
        SaveButton_Video->setGeometry(QRect(10, 280, 331, 31));
        OffButton = new QPushButton(tab_Video);
        OffButton->setObjectName(QString::fromUtf8("OffButton"));
        OffButton->setGeometry(QRect(277, 160, 31, 31));
        tab_manager->addTab(tab_Video, QString());

        hboxLayout->addWidget(tab_manager);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 988, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));
        QObject::connect(quit_button, SIGNAL(clicked()), MainWindowDesign, SLOT(close()));

        tab_manager->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        label_main->setText(QString());
        groupBox_12->setTitle(QApplication::translate("MainWindowDesign", "Logging", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowDesign", "Ros Master", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowDesign", "Ros Master Url", 0, QApplication::UnicodeUTF8));
        line_edit_master->setText(QApplication::translate("MainWindowDesign", "http://192.168.1.2:11311/", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowDesign", "Ros IP", 0, QApplication::UnicodeUTF8));
        line_edit_host->setText(QApplication::translate("MainWindowDesign", "192.168.1.67", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowDesign", "Ros Hostname", 0, QApplication::UnicodeUTF8));
        line_edit_topic->setText(QApplication::translate("MainWindowDesign", "unused", 0, QApplication::UnicodeUTF8));
        checkbox_use_environment->setText(QApplication::translate("MainWindowDesign", "Use environment variables", 0, QApplication::UnicodeUTF8));
        checkbox_remember_settings->setText(QApplication::translate("MainWindowDesign", "Remember settings on startup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_connect->setToolTip(QApplication::translate("MainWindowDesign", "Set the target to the current joint trajectory state.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        button_connect->setStatusTip(QApplication::translate("MainWindowDesign", "Clear all waypoints and set the target to the current joint trajectory state.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        button_connect->setText(QApplication::translate("MainWindowDesign", "Connect", 0, QApplication::UnicodeUTF8));
        quit_button->setText(QApplication::translate("MainWindowDesign", "Quit", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(tab_status), QApplication::translate("MainWindowDesign", "Ros Communications", 0, QApplication::UnicodeUTF8));
        CapturedImage->setText(QString());
        PathButton->setText(QApplication::translate("MainWindowDesign", "Path", 0, QApplication::UnicodeUTF8));
        CaptureButton->setText(QApplication::translate("MainWindowDesign", "Capture", 0, QApplication::UnicodeUTF8));
        SaveButton->setText(QApplication::translate("MainWindowDesign", "Save", 0, QApplication::UnicodeUTF8));
        label_Date->setText(QApplication::translate("MainWindowDesign", "yymmdd", 0, QApplication::UnicodeUTF8));
        label_dash->setText(QApplication::translate("MainWindowDesign", "__", 0, QApplication::UnicodeUTF8));
        label_Description->setText(QApplication::translate("MainWindowDesign", "Description", 0, QApplication::UnicodeUTF8));
        label_dash2->setText(QApplication::translate("MainWindowDesign", "__", 0, QApplication::UnicodeUTF8));
        label_ID->setText(QApplication::translate("MainWindowDesign", "ID", 0, QApplication::UnicodeUTF8));
        label_png->setText(QApplication::translate("MainWindowDesign", ".png", 0, QApplication::UnicodeUTF8));
        label_caputred->setText(QApplication::translate("MainWindowDesign", "                                    No image", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(tab_Image), QApplication::translate("MainWindowDesign", "Image", 0, QApplication::UnicodeUTF8));
        PathButton_Video->setText(QApplication::translate("MainWindowDesign", "Path", 0, QApplication::UnicodeUTF8));
        RecordButton->setText(QApplication::translate("MainWindowDesign", "Record", 0, QApplication::UnicodeUTF8));
        StopButton->setText(QApplication::translate("MainWindowDesign", "Stop", 0, QApplication::UnicodeUTF8));
        label_avi->setText(QApplication::translate("MainWindowDesign", ".avi", 0, QApplication::UnicodeUTF8));
        label_Description_Video->setText(QApplication::translate("MainWindowDesign", "Description", 0, QApplication::UnicodeUTF8));
        label_dash2_2->setText(QApplication::translate("MainWindowDesign", "__", 0, QApplication::UnicodeUTF8));
        label_dash_Video->setText(QApplication::translate("MainWindowDesign", "__", 0, QApplication::UnicodeUTF8));
        label_Date_Video->setText(QApplication::translate("MainWindowDesign", "yymmdd", 0, QApplication::UnicodeUTF8));
        label_ID_Video->setText(QApplication::translate("MainWindowDesign", "ID", 0, QApplication::UnicodeUTF8));
        SaveButton_Video->setText(QApplication::translate("MainWindowDesign", "Save", 0, QApplication::UnicodeUTF8));
        OffButton->setText(QApplication::translate("MainWindowDesign", "Off", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(tab_Video), QApplication::translate("MainWindowDesign", "Video", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
