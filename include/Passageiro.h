/*
 * Arquivo: Passageiro.h 
 * Autor: Lorenna Mirely de Sousa Silva
 * Data: 30/06/2026
 * Descrição:
 * Cabeçalho da classe Passageiro, responsável por definir os métodos e atributos para caracterizar um objeto do tipo Passageiro. 
 * Cada passageiro possui nome e local atual, que é a cidade onde ele se encontra no momento. Podemos definir onde o local onde o o passageiro está por meio de outros métodos. 
*/

#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
#include "Cidade.h"

using namespace std;

class Passageiro {
private:
    string nome;
    Cidade* localAtual;

    public:
    Passageiro(string nome, Cidade* localAtual);

    string getNome();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
};

#endif