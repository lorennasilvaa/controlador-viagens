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

    cout << "Carregando dados...\n\n";

    sistema.carregarDados();

    cout << "\nEstado após carregar:\n";
    sistema.relatarEstado();

    return 0;
}   
