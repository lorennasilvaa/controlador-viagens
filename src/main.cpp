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
    sistema.cadastrarCidade("Macaíba");
    sistema.cadastrarCidade("São Gonçalo do Amarante");
    sistema.cadastrarCidade("Extremoz");

    sistema.cadastrarTrajeto(
        "Natal",
        "Parnamirim",
        'T',
        120
    );

    sistema.cadastrarTrajeto(
        "Natal",
        "Macaíba",
        'T',
        80
    );

    sistema.cadastrarTrajeto(
        "Natal",
        "São Gonçalo do Amarante",
        'T',
        100
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

    sistema.cadastrarTransporte(
        "Carro",
        'C',
        4,
        80,
        200,
        1,
        "Natal"
    );

    sistema.cadastrarPassageiro(
        "João",
        "Natal"
    );

    sistema.cadastrarPassageiro(
        "Maria",
        "Natal"
    );

    vector<string> nomes;
    
    nomes.push_back("João");
    nomes.push_back("Maria");
    
    sistema.iniciarViagem(
        "Ônibus",
        nomes,
        "Natal",
        "Parnamirim"
    );
    
    sistema.iniciarViagem(
        "Carro",
        nomes,
        "Natal",
        "Macaíba"
    );

    
    sistema.relatarViagens();
    sistema.avancarHoras(1);
    sistema.avancarHoras(1);
    sistema.relatarCidadesMaisVisitadas();


    //sistema.relatarPassageiros();
    //sistema.relatarTransportes();
    return 0;
}   
