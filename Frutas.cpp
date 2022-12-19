#include <iostream> 
#include <string>
#include "DetectarRosto.h"
#include "Frutas.h"

using namespace std; 

Frutas::Frutas() {
    frutaAtual = "banana.png";
    this->posicaoX = (rand() % 840);
    this->posicaoY = (rand() % 600);
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

void Frutas::setFrutaAtual(string frutaAtual) {
    this->frutaAtual = frutaAtual;

}

string Frutas::getFrutaAtual() {
    return this->frutaAtual;
}
