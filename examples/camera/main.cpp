#include <stdlib.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/io/vpImageStorageWorker.h>
#include <memory.h>

#include "BaseCamera.h"
#include "Camera.h"

#define USE_COLOR
 
using namespace std;

int main()
{
  int opt_device = 1;
  string opt_seqname;
  int opt_record_mode = 0;

  cout << "Enter camera ID (0, 1, 2, ...):" << endl;
  cin >> opt_device;

  try 
  {
    shared_ptr<BaseCamera> camera = make_shared<Camera>(opt_device); // open the default camera

    if (!camera->isOpened()) 
    {
      cout << endl << "Failed to open the camera" << endl;
      if (opt_device) cout << "Try to enter diffrent integer number, if ineffectualy, use initial main code" << endl;
    }
    cv::Mat frame;
    camera->readFrame(frame);

    cout << endl << "Image size : " << frame.rows << " " << frame.cols << endl;

    vpImage<vpRGBa> I; // To acquire color images

    vpImageConvert::convert(frame, I);

    vpDisplayOpenCV *d = NULL;
    d = new vpDisplayOpenCV(I);

    vpImageQueue<vpRGBa> image_queue(opt_seqname, opt_record_mode);
    vpImageStorageWorker<vpRGBa> image_storage_worker(ref(image_queue));
    thread image_storage_thread(&vpImageStorageWorker<vpRGBa>::run, &image_storage_worker);

    bool quit = false;
    while (!quit) 
    {
      double t = vpTime::measureTimeMs();
      camera->readFrame(frame); // get a new frame from camera
      // Convert the image in ViSP format and display it
      vpImageConvert::convert(frame, I);

      vpDisplay::display(I);

      quit = image_queue.record(I);

      stringstream ss;
      ss << "Acquisition time: " << setprecision(3) << vpTime::measureTimeMs() - t << " ms";
      vpDisplay::displayText(I, I.getHeight() - 20, 10, ss.str(), vpColor::red);
      vpDisplay::flush(I);
    }
    image_queue.cancel();
    image_storage_thread.join();

    if (d) 
    {
      delete d;
    }
  } 
  catch (const vpException &e) 
  {
    cout << "Catch an exception: " << e << endl;
  }
}