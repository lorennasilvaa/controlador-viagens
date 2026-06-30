#include <string>
#include <iostream>
#include "Cidade.h"
#include "Trajeto.h"
using namespace std;

int main()
{
    Cidade c1("Natal"); 
    Cidade c2("Recife");
    Trajeto t1(&c1, &c2, 'T', 300);
    cout << t1.getOrigem()->getNome() << endl;
    cout << t1.getDestino()->getNome() << endl;
    cout << t1.getTipo() << endl;
    cout << t1.getDistancia() << endl;
    return 0;
}
