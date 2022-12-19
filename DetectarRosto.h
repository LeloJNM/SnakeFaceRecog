#include <iostream> 
#include <string>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "Pontuacao.h"
#include "Frutas.h"
#include <windows.h>
#include <Mmsystem.h> 


using namespace cv;
using namespace std;
#pragma once

class DetectarRosto {
public:
    DetectarRosto();
    ~DetectarRosto();
    void detectAndDraw(Mat& img, CascadeClassifier& cascade, double scale, bool tryflip, Pontuacao &pontuacao);
    void verificaSeTemRostoEAtualizaPontuacao(vector<Rect> faces, Pontuacao &pontuacao);
    void drawTransparency(Mat frame, Mat transp, int xPos, int yPos);
private:
    vector<cv::Rect> faces;
    cv::Mat gray, smallImg;
    cv::VideoCapture capture;
    cv::Mat frame;
    bool tryflip;
    cv::CascadeClassifier cascade;
    double scale;
    cv::Scalar color = Scalar(255,0,0);
    Frutas fruta;
};