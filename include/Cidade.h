/*
 * Arquivo: Cidade.h 
 * Autor: Lorenna Mirely de Sousa Silva
 * Data: 30/06/2026
 * Descrição:
 * Cabeçalho da classe cidade, responsável por definir os métodos e atributos para caracterizar um objeto do tipo Cidade. 
*/

#ifndef CIDADE_H
#define CIDADE_H

#include <string>

using namespace std;

class Cidade
{
private:
    string nome; 
    int visitas; // quantidade de vezes que a cidade foi visitada

public:
    Cidade(string nome);
    string getNome();
    int getVisitas();
    void setVisitas(int visitas);
    void incrementarVisitas();
};

#endif