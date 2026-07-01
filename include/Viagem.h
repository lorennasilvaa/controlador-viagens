#ifndef VIAGEM_H
#define VIAGEM_H

#include <vector>

#include "Transporte.h"
#include "Passageiro.h"
#include "Cidade.h"
#include "Trajeto.h"

using namespace std;

class Viagem {

private:
    Transporte* transporte;
    vector<Passageiro*> passageiros;

    Viagem* proxima;

    Trajeto* trajeto;
    
    int horasRestantes;
    bool emAndamento;

public:
    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto);

    void iniciarViagem();
    void avancarHoras(int horas);
    bool isEmAndamento();

    Trajeto* getTrajeto();
    Transporte* getTransporte();

    vector<Passageiro*> getPassageiros();
    
    void setProxima(Viagem* v);
    Viagem* getProxima();

    void relatarEstado();
};

#endif