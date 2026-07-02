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

    sistema.carregarDados();

    sistema.cadastrarCidade("Natal");
    sistema.cadastrarCidade("Recife");


    sistema.cadastrarTrajeto(
        "Natal",
        "Recife",
        'T',
        300
    );

    sistema.cadastrarTransporte(
        "Ônibus",
        'T',
        40,
        80,
        400,
        2,
        "Natal"
    );

    sistema.cadastrarPassageiro(
        "João",
        "Natal"
    );

    sistema.salvarDados();

    return 0;
}   
