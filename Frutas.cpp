#include <iostream> 
#include <string>
#include "DetectarRosto.h"
#include "Frutas.h"

using namespace std; 

Frutas::Frutas() {
}

Frutas::~Frutas() {
}

void Frutas::setFruta(string fruta) {
    this->fruta = fruta;
}

string Frutas::getFruta() {
    return this->fruta;
}

void Frutas::setPosicaoX(int posicaoX) {
    this->posicaoX = posicaoX;
}

int Frutas::getPosicaoX() {
    return this->posicaoX;
}

void Frutas::setPosicaoY(int posicaoY) {
    this->posicaoY = posicaoY;
}

int Frutas::getPosicaoY() {
    return this->posicaoY;
}

void Frutas::DetectarColisao() { 
     float distanciaDosPontos = sqrt(pow(faces[0].x - posicaoX,2) + pow(faces[0].y - posicaoY,2));
     if (distanciaDosPontos < 250){
            setPosicaoX(rand() % 840);
            setPosicaoY(rand() % 600);
            setFruta(frutas[rand() % 4]);
            PlaySound(TEXT("boom.wav"),NULL, SND_ASYNC);

            //system("start powershell -nologo -command (New-Object Media.SoundPlayer \"C:\\Users\\Pc\\Desktop\\orange\\build\\boom.wav\").PlaySync()&");
//            

    }
}