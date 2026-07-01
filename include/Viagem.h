#include <vector>

#include "Transporte.h"
#include "Passageiro.h"
#include "Cidade.h"

using namespace std;

class Viagem {

private:
    Transporte* transporte;
    vector<Passageiro*> passageiros;

    Cidade* origem;
    Cidade* destino;
    Viagem* proxima;
    
    int horasRestantes;
    bool emAndamento;

public:
    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino);

    void iniciarViagem(int distancia);
    void avancarHoras(int horas);
    void relatarEstado();
    bool isEmAndamento();

    Cidade *getOrigem();
    Cidade *getDestino();
    
    void setProxima(Viagem* v);
    Viagem* getProxima();
};
