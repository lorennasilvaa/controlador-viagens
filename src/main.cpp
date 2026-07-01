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

    Trajeto* t = new Trajeto(
        natal,
        parnamirim,
        'T',
        120
    );

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

    Viagem viagem(
        onibus,
        passageiros,
        t
    );

    viagem.iniciarViagem();

    return 0;
}   
