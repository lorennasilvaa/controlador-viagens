#include "ControladorDeTransito.h"

void ControladorDeTransito::cadastrarCidade(string nome)
{
    this->cidades.push_back(new Cidade(nome));
}


void ControladorDeTransito::iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino)
{
    Transporte* transporte = nullptr;

    Cidade* origem = nullptr;
    Cidade* destino = nullptr;

    vector<Passageiro*> passageirosSelecionados;

    // busca transportes
    for(Transporte* t : transportes){

        if(t->getNome() == nomeTransporte){

            transporte = t;
            break;
        }

    }

    //busca cidades
    for(Cidade* c : cidades){

        if(c->getNome() == nomeOrigem)
            origem = c;

        if(c->getNome() == nomeDestino)
            destino = c;

    }

    if(transporte == nullptr ||
       origem == nullptr ||
       destino == nullptr){

        cout << "Dados inválidos" << endl;
        return;
    }

    // testa se o transporte está na origem
    if(transporte->getLocalAtual()!=origem){

        cout << "Transporte não está na cidade." << endl;
        return;
    }

    // busca passageiros
    for(string nome : nomesPassageiros){
        for(Passageiro* p : passageiros){
            if(p->getNome()==nome){
                if(p->getLocalAtual()!=origem){
                    cout<<"Passageiro fora da cidade."<<endl;
                    return;
                }
                passageirosSelecionados.push_back(p);
            }
        }
    }

    if(passageirosSelecionados.size() > transporte->getCapacidade()){

        cout<<"Capacidade excedida"<<endl;
        return;
    }

    Trajeto* trajeto = buscarTrajeto(origem,destino);

    if(trajeto==nullptr){

        cout<<"Trajeto não encontrado"<<endl;
        return;
    }

    Viagem* viagem = new Viagem(transporte, passageirosSelecionados, trajeto);

    viagem->iniciarViagem();
    viagens.push_back(viagem);
}

void ControladorDeTransito::avancarHoras(int horas)
{
    for(Viagem* v : viagens){

        if(v->isEmAndamento()){
            v->avancarHoras(horas);
        }
    }
}

Trajeto *ControladorDeTransito::buscarTrajeto(Cidade *origem, Cidade *destino)
{
    for(Trajeto* t : trajetos){

        if(
            t->getOrigem() == origem &&
            t->getDestino() == destino
        )
            return t;

    }
    return nullptr;
}
