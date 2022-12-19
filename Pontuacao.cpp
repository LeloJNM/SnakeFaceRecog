#include "Pontuacao.h"
#include <iostream>
#include <string>
//using namespace std;

Pontuacao::Pontuacao() {
}

Pontuacao::~Pontuacao() {
}

void Pontuacao::setPontuacao(int pontuacao) {
    this->pontuacao = pontuacao;
}

int Pontuacao::getPontuacao() {
    return pontuacao;
}

void Pontuacao::adicionaPontuacao(int adicao) {
    pontuacao += adicao;
}

void Pontuacao::salvarPontuacaoEmArquivo(){
    if (lerPontuacaoDoArquivo() < pontuacao){
        std::ofstream arquivoDePontuacao;
        arquivoDePontuacao.open("RECORDS.txt");
        arquivoDePontuacao << pontuacao;
        arquivoDePontuacao.close();
    }
}

int Pontuacao::lerPontuacaoDoArquivo(){
    std::string maiorPontuacaoBuffer;
    int maiorPontuacao;
    std::ifstream RECORDS("RECORDS.txt");
    if(!RECORDS.is_open()){
        return 0;
    }
    std::getline(RECORDS, maiorPontuacaoBuffer);
    maiorPontuacao = std::stoi(maiorPontuacaoBuffer);
    RECORDS.close();
    return maiorPontuacao;
}

std::string Pontuacao::to_String(){
    return std::to_string(pontuacao);
}