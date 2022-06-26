#pragma once
#include <visp3/core/vpImageConvert.h>


class BaseCamera {
public:
    cv::Mat virtual readFrame() = 0;
    cv::Mat virtual readFrame(cv::Mat& image) = 0;
    
    // template<typename Type>
    // vpImage<Type> virtual readVispFrame() {};

    bool virtual isOpened() = 0;
};