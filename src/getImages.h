#ifndef GETIMAGES_H
#define GETIMAGES_H

#include "img_struct.h"
#include <iostream>
#include "pipeline.h"
#include <opencv2/opencv.hpp> 
#include "ros/ros.h"
#include "ros_cv_img/GetRoi.h"
#include <cstdlib>

using namespace std;
using namespace cv;

class GetImages
{
    private:
        img_struct images_struct;
        Pipeline pipe;
    public:
        GetImages();
        img_struct GetPic(void);
        void GetRoi(int argc, char **argv, Mat img, bool debug);
};

#endif