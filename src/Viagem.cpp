#include <iostream>

#include "Viagem.h"
// contrutor da classe Viagem, inicializando os atributos com os valores fornecidos
Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto)
{
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->trajeto = trajeto;
    
    proxima = nullptr;
    horasRestantes = 0;
    emAndamento = false;
}

// função para iniciar a viagem, calculando o tempo estimado com base na distância e na velocidade do transporte
void Viagem::iniciarViagem()
{
    int distancia = trajeto->getDistancia();
    int velocidade = transporte->getVelocidade();
    
    horasRestantes = distancia / velocidade;

    if(distancia % velocidade != 0)
    {
        horasRestantes++;
    }

    emAndamento = true;

    cout << "Viagem iniciada de " << trajeto->getOrigem()->getNome() << " para " << trajeto->getDestino()->getNome() << ". Tempo estimado: " << horasRestantes << " horas." << endl;
}

// função para avançar o tempo da viagem, atualizando o estado da viagem e dos passageiros
void Viagem::avancarHoras(int horas)
{
    if(!emAndamento){
        cout << "A viagem não está em andamento." << endl;
        return;
    }

    horasRestantes -= horas;

    if(horasRestantes <= 0){
        emAndamento = false;
        transporte->setLocalAtual(trajeto->getDestino());
        
        for(Passageiro* p : passageiros){
            p->setLocalAtual(trajeto->getDestino());
        }

        cout << "Viagem concluída! Chegou em " << trajeto->getDestino()->getNome() << "." << endl;

        if (proxima != nullptr)
        {
            // distância será calculada pelo controlador
            // portanto inicia com 0
            proxima->iniciarViagem();
        }
    }
}

//função para verificar se a viagem está em andamento
void Viagem::relatarEstado()
{
    if(emAndamento){
        cout << trajeto->getOrigem()->getNome() << " -> " << trajeto->getDestino()->getNome() << " (" << horasRestantes << " horas restantes)" << endl;
    }
    else{
        cout << "A viagem não está em andamento." << endl;
    }
}

bool Viagem::isEmAndamento()
{
    return emAndamento;
}

Trajeto *Viagem::getTrajeto()
{
    return trajeto;
}

Transporte *Viagem::getTransporte()
{
    return transporte;
}

vector<Passageiro*> Viagem::getPassageiros()
{
    return passageiros;
}

void Viagem::setProxima(Viagem *v)
{
    this->proxima = v;
}

Viagem *Viagem::getProxima()
{
    return proxima;
}
