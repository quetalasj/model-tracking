#include "Camera.h"

Camera::Camera(int& deviceID) : cvGrabber(deviceID) {
    for (int i =0; i < 30; i++) {
        readFrame(); // warm up camera by skiping unread frames
    }
};

Camera::~Camera() {
    cvGrabber.release();
}

cv::Mat Camera::readFrame() {
    cv::Mat image;
    cvGrabber.read(image);
    return image;
}
cv::Mat Camera::readFrame(cv::Mat& image) {
    cvGrabber.read(image);
    return image;
}

bool Camera::isOpened() {
    return cvGrabber.isOpened();
}
