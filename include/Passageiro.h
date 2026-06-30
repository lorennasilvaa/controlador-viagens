#include <string>
#include "Cidade.h"
using namespace std;

class Passageiro {
private:
    string nome;
    Cidade* localAtual;
public:
    Passageiro(string nome, Cidade* localAtual);
    string getNome();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
};