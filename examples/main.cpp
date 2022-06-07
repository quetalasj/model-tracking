#include <iostream>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/io/vpImageIo.h>


int main(int argc, char **argv) {
    std::cout << "Hello, World!" << std::endl;

    vpImage<vpRGBa> I;
    vpImageIo::read(I, argv[1]);
    vpDisplayX d(I, vpDisplay::SCALE_AUTO);
    vpDisplay::setTitle(I, "My Image");
    vpDisplay::display(I);
    vpDisplay::flush(I);
    vpDisplay::getClick(I);
    return 0;
}
