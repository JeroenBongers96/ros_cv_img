#include "ros/ros.h"
#include "ros_cv_img/GetRoi.h"

bool GetRoi(ros_cv_img::GetRoi::Request  &req, ros_cv_img::GetRoi::Response &res)
{
    //image conversiong

    //ROS_INFO("request: x=%ld", (long int)req.input);
    
    res.output = {1,2,3};
    int size = res.output.size();
    std::cout << "size array is " << size << std::endl;
    for(int i = 0; i < 3; i++)
        ROS_INFO("sending back response: [%ld]", (long int)res.output[i]);
    return(true);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "get_roi_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("get_roi", GetRoi);
    ROS_INFO("Ready to get ROI's.");
    ros::spin();
    
    return 0;
}