/*
 * Arquivo: Trajeto.h 
 * Autor: Lorenna Mirely de Sousa Silva
 * Data: 30/06/2026
 * Descrição:
 * Cabeçalho da classe Trajeto, responsável por definir os métodos e atributos para caracterizar um objeto do tipo Trajeto. 
 * Cada trajeto possui cidade de origem e cidade de destino, o tipo do trajeto e a distância entre origem e destino. 
*/

#ifndef TRAJETO_H
#define TRAJETO_H

#include "Cidade.h"

class Trajeto {
private:
    Cidade* origem;
    Cidade* destino;

    char tipo; // 'A' para Aquático, 'T' para Terrestre
    int distancia;

public:
    Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia);

    Cidade* getOrigem();
    Cidade* getDestino();

    char getTipo();
    int getDistancia();
};

#endif