#include "getImages.h"

using namespace std;

GetImages::GetImages()
{
    //Uncomment when using camera
    //pipe.pipeStart();
    cout << "GETIMAGES CREATED" << endl;
}

img_struct GetImages::GetPic(void)
{
    images_struct = pipe.getFrames();
    return images_struct;
}

void GetImages::GetRoi(int argc, char **argv, Mat img, bool debug)
{
    Mat rgb_img = img;

    ros::init(argc, argv, "get_roi_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<ros_cv_img::GetRoi>("get_roi");
    ros_cv_img::GetRoi srv;
    
    srv.request.input = 1;
    if (client.call(srv))
    {
        for(int i = 0; i < 3; i++)
            ROS_INFO("Sum: %ld", (long int)srv.response.output[i]);
    }
    else
    {
        ROS_ERROR("Failed to call service get_roi");
    }

    if(debug)
    {
        //show rgb image
        namedWindow("Display Image", WINDOW_AUTOSIZE );
        imshow("Display Image", rgb_img);
        waitKey(0);
    }
}

