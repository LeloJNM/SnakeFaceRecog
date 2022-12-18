#pragma once
#include <iostream>
#include <fstream>



class Pontuacao
{
public:
    Pontuacao();
    ~Pontuacao();
    void setPontuacao(int pontuacao);
    int getPontuacao();
    void adicionaPontuacao(int adicao);
    void salvarPontuacaoEmArquivo();
    int lerPontuacaoDoArquivo();
    std::string to_String();

private:
int pontuacao = 0;

};

