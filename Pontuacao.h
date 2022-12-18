#pragma once


class Pontuacao
{
public:
    Pontuacao();
    ~Pontuacao();
    void setPontuacao(int pontuacao);
    int getPontuacao();
    void adicionaPontuacao(int adicao);
    
private:
int pontuacao = 0;

};

