#include <string>
#include <iostream>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"
using namespace std;

int main()
{
    Cidade c1("Natal"); 
    Cidade c2("Recife"); 
    
    vector<Passageiro> pessoas;
    pessoas.push_back(Passageiro("Lorenna", &c1));
    pessoas.push_back(Passageiro("Thallys", &c1));
    pessoas.push_back(Passageiro("Luiz Arthur", &c1));

    Transporte guanabara("Ônibus Guanabara", 'T', 50, 80, 1, 1, &c1); 
    //Viagem natal_recife(&guanabara, &pessoas, &c1, &c2);
    return 0;
}
