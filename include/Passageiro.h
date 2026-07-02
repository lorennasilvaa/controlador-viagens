/*
 * Arquivo: Passageiro.h 
 * Autor: Lorenna Mirely de Sousa Silva
 * Data: 30/06/2026
 * Descrição:
 * Cabeçalho da classe Passageiro, responsável por definir os métodos e atributos para caracterizar um objeto do tipo Passageiro. 
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