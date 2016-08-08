#ifndef CAPTURE_HPP
#define CAPTURE_HPP

#include <ros/ros.h>
#include <eigen3/Eigen/Dense>
#include <opencv3/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv3/core/eigen.hpp>


class ImageConverter
{
  ros::NodeHandle nh;
  ros::Subscriber image_sub;
  ros::Publisher image_pub;
  cv::Mat input_image;

public:
  ImageConverter(ros::NodeHandle _nh)
    : nh(_nh)
  {
      image_pub = nh.advertise<sensor_msgs::Image>("/test", 1);
      image_sub = nh.subscribe("/camera/image", 1, &ImageConverter::imageCb, this);
  }

  ~ImageConverter()
  {

  }
  void imageCb(const sensor_msgs::ImageConstPtr& msg)
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
  void record()
  {
         cv::VideoWriter vrecord("/home/marco/marco_ws/src/image_listener/MyVideo.avi", CV_FOURCC('P','I','M','1'), 20, input_image.size(), true);

         if(!vrecord.isOpened())
         {
             printf("ERROR: Failed to write the video");
             return ;
         }

         while(ros::ok())
             vrecord.write(input_image);

  }

  void capture()
  {
      cv::Mat test_image(480, 640, CV_8UC3);
      std::cout << test_image.size() << std::endl;
      cv::imwrite("/home/marco/marco_ws/src/image_listener/abc.jpg", input_image);
  }

  void publish()
  {
      cv_bridge::CvImagePtr image_converter(new cv_bridge::CvImage());
      image_converter->header.frame_id = "test";
      image_converter->header.stamp = ros::Time::now();
      image_converter->encoding = sensor_msgs::image_encodings::TYPE_8UC3;
      image_converter->image = input_image;
      image_pub.publish(image_converter->toImageMsg());
  }

  void run()
  {
      ros::spinOnce();


      if(input_image.empty())
          return;
      std::cout << "put command : " << std::endl;
      char a = getchar();
      if(a == 'r')
      {
          std::cout << "start record" << std::endl;
        record();
        std::cout << "recorded" << std::endl;
      }
      else if(a == 'c')
      {
          std::cout << "start capture" << std::endl;
        capture();
        std::cout << "captured." << std::endl;
      }
      else
      {
          std::cout << "error" << std::endl;
          return;
      }

//      publish();
  }
  bool init()
  {

  }


};

#endif // CAPTURE_CPP
//int main(int argc, char** argv)
//{
//    ros::init(argc, argv, "image_converter");
//    ros::NodeHandle nh;
//    ImageConverter ic(nh);
//    ros::Rate loop_rate(10);
//    while(ros::ok())
//    {
//        ic.run();
//        loop_rate.sleep();
//    }
//    return 0;
//}

