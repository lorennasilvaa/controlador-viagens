/* Representa um trajeto no sistema
 * Cada trajeto possui cidade de origem e cidade de destino, o tipo do trajeto e a distância entre origem e destino. 
*/

#include "Trajeto.h"

Trajeto::Trajeto(Cidade *origem, Cidade *destino, char tipo, int distancia)
{
    this->origem = origem;
    this->destino = destino; 
    this->tipo = tipo; 
    this->distancia = distancia;
}

Cidade *Trajeto::getOrigem()
{
    return origem;
}

Cidade *Trajeto::getDestino()
{
    return destino;
}

char Trajeto::getTipo()
{
    return tipo;
}

int Trajeto::getDistancia()
{
    return distancia;
}
