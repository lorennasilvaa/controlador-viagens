#include <string>
#include <iostream>
#include <limits>

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

    sistema.carregarDados();

    int opcao;

    do
    {
        cout << "\n=========================================\n";
        cout << "      CONTROLADOR DE VIAGENS\n";
        cout << "=========================================\n";
        cout << "1 - Cadastrar cidade\n";
        cout << "2 - Cadastrar trajeto\n";
        cout << "3 - Cadastrar transporte\n";
        cout << "4 - Cadastrar passageiro\n";
        cout << "5 - Iniciar viagem\n";
        cout << "6 - Avancar horas\n";
        cout << "7 - Relatorios\n";
        cout << "0 - Salvar e sair\n";
        cout << "=========================================\n";
        cout << "Opcao: ";

        cin >> opcao;

        switch(opcao)
        {
            case 1:
            {
                string nomeCidade;

                cout << "\n===== CADASTRO DE CIDADE =====\n";
                cout << "Nome da cidade: ";
                
                cin.ignore(); 
                getline(cin, nomeCidade);

                sistema.cadastrarCidade(nomeCidade);

                cout << "Cidade cadastrada com sucesso!\n";
                break;
            }
            case 2:
            {
                string origem, destino;
                char tipo;
                int distancia;

                cout << "\n===== CADASTRO DE TRAJETO =====\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Cidade de origem: ";
                getline(cin, origem);

                cout << "Cidade de destino: ";
                getline(cin, destino);

                cout << "Tipo (T = Terrestre | A = Aquatico): ";
                cin >> tipo;

                cout << "Distancia (km): ";
                cin >> distancia;

                sistema.cadastrarTrajeto(origem, destino, toupper(tipo), distancia);

                break;
            }
            
            case 3:
            {
                string nome;
                string cidade;

                char tipo;

                int capacidade;
                int velocidade;
                int distanciaEntreDescansos;
                int tempoDescanso;

                cout << "\n===== CADASTRO DE TRANSPORTE =====\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Nome: ";
                getline(cin, nome);

                cout << "Tipo (T = Terrestre | A = Aquatico): ";
                cin >> tipo;

                cout << "Capacidade: ";
                cin >> capacidade;

                cout << "Velocidade (km/h): ";
                cin >> velocidade;

                cout << "Distancia entre descansos (km): ";
                cin >> distanciaEntreDescansos;

                cout << "Tempo de descanso (h): ";
                cin >> tempoDescanso;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Cidade atual: ";
                getline(cin, cidade);

                sistema.cadastrarTransporte(
                    nome,
                    toupper(tipo),
                    capacidade,
                    velocidade,
                    distanciaEntreDescansos,
                    tempoDescanso,
                    cidade
                );

                break;
            }   
                
            case 4:
            {
                string nome;
                string cidade;

                cout << "\n===== CADASTRO DE PASSAGEIRO =====\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Nome: ";
                getline(cin, nome);

                cout << "Cidade atual: ";
                getline(cin, cidade);

                sistema.cadastrarPassageiro(nome, cidade);

                break;
            }

            case 5:
            {
                string transporte;
                string origem;
                string destino;

                int quantidade;

                vector<string> passageiros;

                cout << "\n===== INICIAR VIAGEM =====\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Transporte: ";
                getline(cin, transporte);

                cout << "Origem: ";
                getline(cin, origem);

                cout << "Destino: ";
                getline(cin, destino);

                cout << "Quantidade de passageiros: ";
                cin >> quantidade;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                for(int i = 0; i < quantidade; i++)
                {
                    string nome;

                    cout << "Passageiro " << i + 1 << ": ";
                    getline(cin, nome);

                    passageiros.push_back(nome);
                }

                sistema.iniciarViagem(
                    transporte,
                    passageiros,
                    origem,
                    destino);

                break;
            }

            case 6:
            {
                int horas;

                cout << "\n===== AVANÇAR TEMPO =====\n";

                cout << "Quantidade de horas: ";
                cin >> horas;

                sistema.avancarHoras(horas);

                break;
            }

            case 7:
            {
                sistema.relatarEstado();
                break;
            }
            
            case 0:
            {
                cout << "\nSalvando dados...\n";

                sistema.salvarDados();

                cout << "Dados salvos com sucesso!\n";
                cout << "Encerrando o sistema...\n";

                break;
            }

            default:
                cout << "\nOpcao invalida!\n";
        }

    } while(opcao != 0);

    return 0;
}   
