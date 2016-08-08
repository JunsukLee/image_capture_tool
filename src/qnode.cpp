/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include "qnode.hpp"

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace image_capture_tool {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init(std::string Topic) {
	ros::init(init_argc,init_argv,"image_capture_tool");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    image_sub = n.subscribe(Topic, 1, &QNode::subscribeInputImageCallback, this);
	start();
    record_flag = false;
    capture_flag = false;
    hz = 30;
    return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url, std::string Topic) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"image_capture_tool");
	if ( ! ros::master::check() ) {
		return false;
    }
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    image_sub = n.subscribe(Topic, 1, &QNode::subscribeInputImageCallback, this);
	start();
    record_flag = false;
    capture_flag = false;
    hz = 30;
	return true;
}

void QNode::run() {
    ros::Rate loop_rate(hz);
	int count = 0;
	while ( ros::ok() ) {


        ros::spinOnce();
        if(!input_image.empty())
        {
            Q_EMIT mainwindowUpdated();
            if(record_flag)
                recording();
         }

		loop_rate.sleep();
        ++count;
    }
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
    Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}
void QNode::setFrequency(const int _hz)
{
    hz = _hz;
}
void QNode::record(const double _fps, const std::string _path, const std::string _filename)
{
    double fps = _fps;
    int fourcc = CV_FOURCC('P','I','M','1');

    bool isColor = true;
    std::cout << input_image.size() << std::endl;
    std::string name = _path + "/" + _filename;

    video = new cv::VideoWriter;
    if(!video->open(name, fourcc, fps, input_image.size(), isColor)){
        std::cerr << "[ERROR] : Video File is not opened" << std::endl;
        delete video;
        return;
    }



    record_flag = true;
//    while(record_flag)
//    {
//        *video << input_image;
//    }
}
void QNode::recording()
{
    (*video) << input_image;
}

cv::Mat QNode::getInputImage()
{
    return input_image;
}

cv::Mat QNode::getCapturedImage()
{
    return captured_image;
}

void QNode::capture()
{
    input_image.copyTo(captured_image);
    capture_flag = true;
}
bool QNode::isCaptured()
{
    return capture_flag;
}
void QNode::stopRecord()
{
    delete video;
    record_flag = false;
}

void QNode::saveCapturedImage(const std::string _path, const std::string _filename)
{
    std::string name = _path + "/" + _filename;
    cv::imwrite(name, captured_image);
    capture_flag = false;
}

void QNode::subscribeInputImageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    cv_bridge::CvImagePtr cv_ptr;//(new cv_bridge::CvImage);
    try
      {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    input_image = cv_ptr->image;

      }
    catch (cv_bridge::Exception& e)
      {
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
      }
}
}  // namespace image_capture_tool
