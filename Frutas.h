#include <iostream>
#include <string>
#include <random>
#include <cmath>


using namespace std;

#pragma once

class Frutas
{
public:
    Frutas();
    ~Frutas();

    void setFruta(string fruta);
    string getFruta();
    void setFrutaAtual(string frutaAtual);
    string getFrutaAtual();
    void setPosicaoX(int posicaoX);
    int getPosicaoX();
    void setPosicaoY(int posicaoY);
    int getPosicaoY();
    string frutas[4] = {"banana.png", "laranja.png", "uva.png","abacaxi.png"};

private:
    string fruta;
    string frutaAtual;
    int posicaoX;
    int posicaoY;

};

