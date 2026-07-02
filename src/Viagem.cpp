/* Representa uma viagem no sistema
 * Cada viagem possui o transporte que será utilizado, um vetor de passageiros que farão parte da viagem, o trajeto que será executado, as horas restantes para o término da viagem e se ela está em andamento ou não.
*/

#include <iostream>

#include "Viagem.h"

Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto)
{
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->trajeto = trajeto;
    
    proxima = nullptr; // ponteiro para a proxima viagem (caso seja uma viagem intermediaria)
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
        
        trajeto->getDestino()->incrementarVisitas(); // incrementa a quantidade de visitas da cidade de destino
        // altera o local de todos os passageiros ao fim da viagem para o local de destino
        // ALTERAR ISSO AQUI PARA SÓ MOVER OS PASSAGEIROS PARA O LOCAL DE DESTINO FINAL EM VIAGENS INTERMEDIARIAS
        for(Passageiro* p : passageiros){
            p->setLocalAtual(trajeto->getDestino());
        }

        cout << "Viagem concluída! Chegou em " << trajeto->getDestino()->getNome() << "." << endl;

        if (proxima != nullptr)
        {
            // chama a proxima viagem, caso a viagem atual seja uma viagem intermediaria
            proxima->iniciarViagem();
        }
    }
}

//função para relatar estado da viagem, mostrando origem, destino e horas restantes
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
