#include "DetectarRosto.h"
#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <windows.h>
#include <Mmsystem.h> 

DetectarRosto::DetectarRosto(){
}

DetectarRosto::~DetectarRosto(){
}

void DetectarRosto::drawTransparency(Mat frame, Mat transp, int xPos, int yPos){
    Mat mask;
    vector<Mat> layers;

    split(transp, layers); // seperate channels
    Mat rgb[3] = {layers[0], layers[1], layers[2]};
    mask = layers[3];      // png's alpha channel used as mask
    merge(rgb, 3, transp); // put together the RGB channels, now transp insn't transparent
    transp.copyTo(frame.rowRange(yPos, yPos + transp.rows).colRange(xPos, xPos + transp.cols), mask);
}

// void drawTransRect(Mat frame, Scalar color, double alpha, Rect region) {
//     Mat roi = frame(region);
//     Mat rectImg(roi.size(), CV_8UC3, color);
//     addWeighted(rectImg, alpha, roi, 1.0 - alpha , 0, roi);
// }
//desenha os quadrados nos rostos e o placar
void DetectarRosto::detectAndDraw(Mat &img, CascadeClassifier &cascade, double scale, bool tryflip, Pontuacao &pontuacao) {
    double t = 0;
    vector<Rect> faces;
    Mat gray, smallImg;
    Scalar color = Scalar(255, 0, 0);

    if (tryflip){
        flip(img, img, 1);
    }

    cvtColor(img, gray, COLOR_BGR2GRAY);
    double fx = 1 / scale;
    resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);
    equalizeHist(smallImg, smallImg);

    t = (double)getTickCount();

    cascade.detectMultiScale(smallImg, faces,
                             1.3, 2, 0
                                         //|CASCADE_FIND_BIGGEST_OBJECT
                                         //|CASCADE_DO_ROUGH_SEARCH
                                         | CASCADE_SCALE_IMAGE,
                             Size(40, 40));
    t = (double)getTickCount() - t;
    // PERCORRE AS FACES ENCONTRADAS
    for (size_t i = 0; i < faces.size(); i++){
        Rect r = faces[i];
        rectangle(img, Point(cvRound(r.x * scale), cvRound(r.y * scale)),
                  Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
                  color, 3);


    }
    this->verificaSeTemRostoEAtualizaPontuacao(faces, pontuacao);
    Mat overlay = cv::imread(fruta.getFrutaAtual(), IMREAD_UNCHANGED);
    drawTransparency(img, overlay, fruta.getPosicaoX(), fruta.getPosicaoY());

    // // Desenha quadrados com transparencia
    // double alpha = 0.3;
    // drawTransRect(img, Scalar(0,255,0), alpha, Rect(  0, 0, 200, 200));
    // drawTransRect(img, Scalar(255,0,0), alpha, Rect(200, 0, 200, 200));

    // Desenha um texto
    color = Scalar(0,0,255);
    putText	(img, "Placar:" + pontuacao.to_String(), Point(300, 50), FONT_HERSHEY_PLAIN, 2, color); // fonte
    
    // Desenha o frame na tela
        imshow( "result", img );
}
void DetectarRosto::verificaSeTemRostoEAtualizaPontuacao(vector<Rect> faces, Pontuacao &pontuacao){
    // Verifica se a comida foi pega e gerar uma nova
    if (faces.size() > 0){
        float distanciaDosPontos = sqrt(pow(faces[0].x - fruta.getPosicaoX(), 2) + pow(faces[0].y - fruta.getPosicaoY(), 2));
        if (distanciaDosPontos < 250){
            fruta.setPosicaoX(rand() % 840) ;
            fruta.setPosicaoY(rand() % 600) ;
            fruta.setFrutaAtual(fruta.frutas[rand() % 4]);
            pontuacao.adicionaPontuacao(1);
            // system("start powershell -nologo -command (New-Object Media.SoundPlayer \"C:\\Users\\Pc\\Desktop\\orange\\build\\boom.wav\").PlaySync()&");
            PlaySound(TEXT("boom.wav"), NULL, SND_ASYNC);
        }
    }
}

