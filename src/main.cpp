#include <string>
#include <iostream>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
using namespace std;

int main()
{
    Cidade c1("Natal"); 
    Cidade c2("Recife"); 
    Passageiro p("Lorenna", &c1);
    cout << p.getNome() << endl;
    cout << p.getLocalAtual()->getNome() << endl;
    p.setLocalAtual(&c2);
    cout << p.getLocalAtual()->getNome() << endl;
    return 0;
}
