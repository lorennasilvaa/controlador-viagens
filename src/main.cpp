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
    Cidade* natal = new Cidade("Natal");
    Cidade* parnamirim = new Cidade("Parnamirim");
    Cidade* macaiba = new Cidade("Macaíba");

    Trajeto* t1 = new Trajeto(natal, parnamirim,'T', 100);

    Trajeto* t2 = new Trajeto(parnamirim, macaiba,'T', 60);

    Transporte* onibus = new Transporte(
        "Ônibus",
        'T',
        40,
        60,
        300,
        2,
        natal
    );

    Passageiro* p1 = new Passageiro("João", natal);
    Passageiro* p2 = new Passageiro("Maria", natal);

    vector<Passageiro*> passageiros;

    passageiros.push_back(p1);
    passageiros.push_back(p2);

    Viagem* v1 = new Viagem(onibus,passageiros,t1);

    Viagem* v2 =new Viagem(onibus,passageiros,t2);

    v1->setProxima(v2);

    v1->iniciarViagem();

    v1->avancarHoras(2);
    v2->relatarEstado();
    
    return 0;
}   
