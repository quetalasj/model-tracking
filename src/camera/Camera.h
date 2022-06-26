#pragma once
#include "BaseCamera.h"


class Camera: public BaseCamera
{
private:
    cv::VideoCapture cvGrabber;

public:
    Camera(int& deviceID);
    ~Camera();

    cv::Mat readFrame() override;
    cv::Mat readFrame(cv::Mat& image) override;
    

    bool isOpened() override;
};


