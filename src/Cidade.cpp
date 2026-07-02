/* Representa uma cidade no sistema
 * Cada cidade possui um nome 
*/

#include "Cidade.h"

Cidade::Cidade(string nome)
{
    this->nome = nome;
    this->visitas = 0;
}

string Cidade::getNome()
{
    return nome;
}

int Cidade::getVisitas()
{
    return visitas;
}

void Cidade::incrementarVisitas()
{
    visitas++;
}

