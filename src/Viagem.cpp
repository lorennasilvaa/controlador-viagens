#include <iostream>

#include "Viagem.h"
// contrutor da classe Viagem, inicializando os atributos com os valores fornecidos
Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino)
{
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->origem = origem;
    this->destino = destino;
    
    proxima = nullptr;
    horasRestantes = 0;
    emAndamento = false;
}

// função para iniciar a viagem, calculando o tempo estimado com base na distância e na velocidade do transporte
void Viagem::iniciarViagem(int distancia)
{
    int velocidade = transporte->getVelocidade();
    
    horasRestantes = distancia / velocidade;

    if(distancia % velocidade != 0)
    {
        horasRestantes++;
    }

    emAndamento = true;

    cout << "Viagem iniciada de " << origem->getNome() << " para " << destino->getNome() << ". Tempo estimado: " << horasRestantes << " horas." << endl;
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
        transporte->setLocalAtual(destino);
        
        for(Passageiro* p : passageiros){
            p->setLocalAtual(destino);
        }

        cout << "Viagem concluída! Chegou em " << destino->getNome() << "." << endl;

        if (proxima != nullptr)
        {
            // distância será calculada pelo controlador
            // portanto inicia com 0
            proxima->iniciarViagem(0);
        }
    }
}

//função para verificar se a viagem está em andamento
void Viagem::relatarEstado()
{
    if(emAndamento){

        cout << origem->getNome()
             << " -> "
             << destino->getNome()
             << " ("
             << horasRestantes
             << " horas restantes)"
             << endl;
    }
    else{
        cout << "A viagem não está em andamento." << endl;
    }
}

bool Viagem::isEmAndamento()
{
    return emAndamento;
}

Cidade *Viagem::getOrigem()
{
    return origem;
}

Cidade *Viagem::getDestino()
{
    return destino;
}

void Viagem::setProxima(Viagem *v)
{
    proxima = v;
}

Viagem *Viagem::getProxima()
{
    return proxima;
}
