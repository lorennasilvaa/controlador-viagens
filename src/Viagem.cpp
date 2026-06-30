#include "Viagem.h"

Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino)
{
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->origem = origem;
    this->destino = destino;
}

void Viagem::iniciarViagem()
{
    
}
