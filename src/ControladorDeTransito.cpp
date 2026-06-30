#include "ControladorDeTransito.h"

void ControladorDeTransito::cadastrarCidade(string nome)
{
    this->cidades.push_back(new Cidade(nome));
}

void ControladorDeTransito::cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia)
{
    
}
