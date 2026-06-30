#include <string>
#include <iostream>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
using namespace std;

int main()
{
    Cidade c1("Natal"); 
    Transporte t("Barco", 'A', 12, 30, 10, 1, &c1);
    cout << t.getNome() << endl;
    cout << t.getTipo() << endl;
    cout << t.getCapacidade() << endl;
    cout << t.getVelocidade() << endl;
    cout << t.getDistanciaEntreDescansos() << endl;
    cout << t.getTempoDescanso() << endl;
    cout << t.getLocalAtual()->getNome() << endl;
    return 0;
}
