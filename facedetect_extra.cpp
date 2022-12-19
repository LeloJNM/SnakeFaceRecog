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
#include <thread>

using namespace std;
using namespace cv;

string cascadeName;

int getOption();

bool contando = true;

void iniciaTemporizador(bool *contando)
{
    Timer timer;
    timer.timer(contando);
}

int main(int argc, const char **argv)
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

    if (!cascade.load(cascadeName))
    {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        return -1;
    }

    // Objetos
    Pontuacao pontuacao;
    DetectarRosto rosto;

    // Menu
    enum Options
    {
        JOGAR = 1,
        VERPONTUACAO,
        EXIT
    };

    int options = Options::JOGAR;

    while (options != EXIT)
    {
        options = getOption();
        switch (options)
        {
        case JOGAR:
            //if(!capture.open("video.mp4")) // para testar com um video
            if (!capture.open(0)) {
                cout << "Capture from camera #0 didn't work" << endl;
                return 1;
            }
            
            cout << "Begin" << endl;
            if (capture.isOpened()) {
                cout << "Video capturing has been started ..." << endl;

                thread temporizador(iniciaTemporizador, &contando);

                while (contando) {
                    capture >> frame;
                    if (frame.empty())
                        break;

                    rosto.detectAndDraw(frame, cascade, scale, tryflip, pontuacao);

                    char c = (char)waitKey(10);
                    if (c == 27 || c == 'q' || c == 'Q')
                        break;
                }

                system("cls");

                temporizador.join();
                destroyAllWindows();
                frame.release();
                capture.release();
                pontuacao.salvarPontuacaoEmArquivo();
            }

        

        case VERPONTUACAO:
            cout << "Exibindo os records de pontuação";
            cout << pontuacao.lerPontuacaoDoArquivo() << endl;
        default:
            break;
        }
        // FIM DO WHILE
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
    cout << "           Bem vindo ao SnakeRecog" << endl;
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
