#include <string>
#include <iostream>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"
#include "ControladorDeTransito.h"
using namespace std;

int main()
{
    ControladorDeTransito sistema;

    sistema.cadastrarCidade("Natal");
    sistema.cadastrarCidade("Parnamirim");

    sistema.cadastrarTrajeto(
        "Natal",
        "Parnamirim",
        'T',
        120
    );

    sistema.cadastrarTransporte(
        "Ônibus",
        'T',
        40,
        60,
        300,
        2,
        "Natal"
    );

    sistema.cadastrarPassageiro(
        "João",
        "Natal"
    );

    vector<string> nomes;
    
    nomes.push_back("João");
    
    sistema.iniciarViagem(
        "Ônibus",
        nomes,
        "Natal",
        "Parnamirim"
    );

    sistema.avancarHoras(1);
    
    sistema.relatarEstado();
    
    sistema.avancarHoras(1);
    
    sistema.relatarEstado();
    
    return 0;
}   
