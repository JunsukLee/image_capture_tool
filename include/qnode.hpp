/**
 * @file /include/image_capture_tool/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef image_capture_tool_QNODE_HPP_
#define image_capture_tool_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/
#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>

#include <thread>
#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/core/eigen.hpp>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace image_capture_tool {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
    bool init(std::string Topic);
    bool init(const std::string &master_url, const std::string &host_url, std::string Topic);
    void run();

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };


	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);

    void record(const double _fps, const std::string _path, const std::string _filename);
    void recording();
    void capture();
//    void record();
    void saveCapturedImage(const std::string _path, const std::string _filename);

    bool isCaptured();
    void stopRecord();
    void setFrequency(const int _hz);
    cv::Mat getInputImage();
    cv::Mat getCapturedImage();
    QString RosTopic;

Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();
    void mainwindowUpdated();


private:
    cv::VideoWriter* video;
	int init_argc;
	char** init_argv;
	ros::Publisher chatter_publisher;
    QStringListModel logging_model;
    cv::Mat input_image;
    bool capture_flag;
    bool record_flag;
    cv::Mat captured_image;
    int hz;



    ros::Subscriber image_sub;
    void subscribeInputImageCallback(const sensor_msgs::ImageConstPtr& msg);
};

}  // namespace image_capture_tool

#endif /* image_capture_tool_QNODE_HPP_ */
