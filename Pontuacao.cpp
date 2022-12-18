#include "Pontuacao.h"

Pontuacao::Pontuacao()
{

}

Pontuacao::~Pontuacao()
{

}

void Pontuacao::setPontuacao(int pontuacao)
{
    this->pontuacao = pontuacao;
}

int Pontuacao::getPontuacao()
{
    return pontuacao;
}

void Pontuacao::adicionaPontuacao(int adicao)
{
    pontuacao += adicao;
}
