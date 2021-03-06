#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "src/Utils.h"

cv::CascadeClassifier face_cascade;
cv::CascadeClassifier eyes_cascade;

int main(int argc, const char** argv)
{
    cv::CommandLineParser parser(argc, argv, "{help h||}" "{face_cascade|C:/OpenCV/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml|Path to face cascade.}"
                                             "{eyes_cascade|C:/OpenCV/opencv/sources/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}" 
                                             "{capture|D:/Utils/C++/OpenCV/SPOILER_SPOILER_SPOILER_SPOILER_SPOILER_r1.mp4|stream input location.}"
                                             "{frameTitle|test|Sets the name of the frame.}");
    parser.about("\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n" "You can use Haar or LBP features.\n\n");
    parser.printMessage();
    Utils::face_cascade_name = cv::samples::findFile(parser.get<std::string>("face_cascade"));
    Utils::eyes_cascade_name = cv::samples::findFile(parser.get<std::string>("eyes_cascade"));
    Utils::frameTitle = parser.get<std::string>("frameTitle");
    Utils::captureSource = parser.get<std::string>("capture");

    Utils::openAndReadCapture();

}