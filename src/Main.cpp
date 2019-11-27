#include <iostream>
#include "getImages.h"
#include <opencv2/opencv.hpp> 
#include <librealsense2/rs.hpp>
#include <pcl/visualization/pcl_visualizer.h>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    //ros::init(argc, argv, "get_roi_client");
    bool debug = true;
    //For use with camera
    GetImages getimage;
    //img_struct images = getimage.GetPic();
    //cv::Mat color = images.Image;
    //getimage.GetRoi(color);

    //For use with image of pics folder
    string filename = "/home/jeroen/catkin_ws/src/ros_cv_img/pics/Winnie-The-Pooh-Download-PNG.png";
    Mat color = imread(filename);
    getimage.GetRoi(argc, argv,color, debug);

    
    
    

    

    //show pcd
    //pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
    //viewer.addPointCloud (images.Cloud,"pcd");
    //viewer.spin();

    return 0;
}