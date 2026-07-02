/*
 * Arquivo: ControladorDeTransito.h 
 * Autor: Lorenna Mirely de Sousa Silva
 * Data: 01/06/2026
 * Descrição:
 * Cabeçalho da classe ControladorDeTransito, responsável por definir os métodos e atributos para caracterizar um objeto do tipo ControladorDeTransito.  
*/


#ifndef CONTROLADOR_DE_TRANSITO_H
#define CONTROLADOR_DE_TRANSITO_H

#include <vector>
#include <iostream>

#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h" 
#include "Viagem.h"

using namespace std;

class ControladorDeTransito {
private:
    vector<Cidade*> cidades;
    vector<Trajeto*> trajetos;
    vector<Transporte*> transportes;
    vector<Passageiro*> passageiros;
    vector<Viagem*> viagens;

public:
    void cadastrarCidade(string nome);
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia);
    void cadastrarTransporte(string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, string localAtual);
    void cadastrarPassageiro(string nome, string localAtual);

    void iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino);
    void avancarHoras(int horas);
    void relatarEstado(); // relata o estado da viagem
    
    Trajeto* buscarTrajeto(Cidade* origem, Cidade* destino); // busca os trajetos que serão utilizados na viagem

    // Métodos dos relatórios
    void relatarPassageiros();
    //void relatarTransportes();
};

#endif 