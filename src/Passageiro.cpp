/* Representa um passageiro no sistema
 * Cada passageiro possui nome e local atual, que é a cidade onde ele se encontra no momento. Podemos definir onde o local onde o o passageiro está por meio de outros métodos. 
*/

#include "Passageiro.h"

Passageiro::Passageiro(string nome, Cidade *localAtual)
{
    this->nome = nome;
    this->localAtual = localAtual;
}

string Passageiro::getNome()
{
    return nome;
}

Cidade *Passageiro::getLocalAtual()
{
    return localAtual;
}

void Passageiro::setLocalAtual(Cidade *local)
{
    this->localAtual = local;
}
