#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "Pontuacao.h"
#include "DetectarRosto.h"
#include "Frutas.h"
#include "Timer.h"
#include <iostream>
#include <random>
#include <cmath>
#include <Windows.h>
#include <Mmsystem.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <locale>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
using namespace cv;

string cascadeName;

int getOption();

int main( int argc, const char** argv )
{
    setlocale(LC_ALL, "portuguese");
    
    srand((unsigned)time(NULL));

    VideoCapture capture;
    Mat frame;
    bool tryflip;
    CascadeClassifier cascade;
    double scale;
    Frutas fruta;
    int xPos;
    int yPos;
    Mat transp;
    vector<Rect> faces;

    cascadeName = "haarcascade_frontalface_default.xml";
    cascadeName = "haarcascade_frontalface_alt2.xml";
    scale = 1;
    if (scale < 1)
        scale = 1;
    tryflip = true;

    if (!cascade.load(cascadeName)) {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        return -1;
    }

    //    if(!capture.open("video.mp4")) // para testar com um video
    if(!capture.open(0))
    {
        cout << "Capture from camera #0 didn't work" << endl;
        return 1;
    }

    
    Pontuacao pontuacao;
    DetectarRosto rosto;


    enum Options
    {
        JOGAR = 1,
        VERPONTUACAO,
        EXIT
    };

    int options = Options::JOGAR;

    while(options != EXIT)
    {
        options = getOption();
        system("cls");
        switch (options)
        {
        case JOGAR:
            cout << "Begin" << endl;
            if( capture.isOpened() )
    {
        cout << "Video capturing has been started ..." << endl;

        for(;;)
        {
            capture >> frame;
            if( frame.empty() )
                break;

            rosto.detectAndDraw(frame, cascade, scale, tryflip);

            char c = (char)waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }
        rosto.drawTransparency(frame, transp, xPos, yPos);
        rosto.verificaSeTemRostoEAtualizaPontuacao(faces);


        case VERPONTUACAO:
            cout << "Exibindo os records de pontuação" << endl;
            pontuacao.lerPontuacaoDoArquivo();
        default:
        pontuacao.salvarPontuacaoEmArquivo();
            break;
        }
            //FIM DO WHILE
    }



/**
 * @brief Draws a transparent image over a frame Mat.
 * 
 * @param frame the frame where the transparent image will be drawn
 * @param transp the Mat image with transparency, read from a PNG image, with the IMREAD_UNCHANGED flag
 * @param xPos x position of the frame image where the image will start.
 * @param yPos y position of the frame image where the image will start.
 */
}

int getOption()
{
        int in;
        cout << "           Bem vindo ao SnakeHead" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "               1 - Jogar" << endl;
        cout << "               2 - Ver pontuação" << endl;
        cout << "               3 - Sair" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Selecione uma opção [1-3]:" << endl;
        cin >> in;
        cin.ignore();

        return in;
        }
