#include <vector>
#include "Transporte.h"
#include "Passageiro.h"
using namespace std;

class Viagem {
private:
    Transporte* transporte;
    vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;
    Viagem* proxima;
    int horasEmTransito;
    bool emAndamento;
public:
    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino);
    void iniciarViagem();
    void avancarHoras(int horas);
    void relatarEstado();
    bool isEmAndamento();
};
