/* Representa uma cidade no sistema
 * Cada cidade possui um nome 
*/

#include "Cidade.h"

Cidade::Cidade(string nome)
{
    this->nome = nome;
}

string Cidade::getNome()
{
    return nome;
}
