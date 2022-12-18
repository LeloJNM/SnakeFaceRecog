#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include "DetectarRosto.h" 

using namespace std;

#pragma once

class Frutas
{
public:
    Frutas();
    ~Frutas();

    void DetectarColisao();
    void setFruta(string fruta);
    string getFruta();
    void setPosicaoX(int posicaoX);
    int getPosicaoX();
    void setPosicaoY(int posicaoY);
    int getPosicaoY();

private:
    string fruta;
    string frutas[4] = {"banana.png", "laranja.png", "uva.png","abacaxi.png"};
    string frutaAtual;
    int posicaoX;
    int posicaoY;

};

