/* Classe responsável por ser a ponte entre as outras classes.
 * O Controlador de Transito possui uma lista das cidades, trajetos, transportes, passageiros e viagens existentes no sistema. ALém de poder cadastrá-los, ele é responsável por gerenciar as viagens. 
*/

#include "ControladorDeTransito.h"

void ControladorDeTransito::cadastrarCidade(string nome)
{
    this->cidades.push_back(new Cidade(nome));
}

void ControladorDeTransito::cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia)
{
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;

    // encontra o endereço de memória da origem e dos destino baseado nos nomes informados
    for (Cidade* c : cidades)
    {
        if (c->getNome() == nomeOrigem)
            origem = c;

        if (c->getNome() == nomeDestino)
            destino = c;
    }

    if (origem == nullptr || destino == nullptr)
    {
        cout << "Cidade não encontrada." << endl;
        return;
    }

    // cria uma instancia de trajeto
    Trajeto* trajeto = new Trajeto(
        origem,
        destino,
        tipo,
        distancia
    );

    trajetos.push_back(trajeto);

    cout << "Trajeto cadastrado com sucesso!" << endl;
}

void ControladorDeTransito::cadastrarTransporte(string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, string localAtual)
{
    Cidade* cidade = nullptr;

    // encontra o endereço de memória da cidade onde o transporte está situado baseado no nome informado
    for (Cidade* c : cidades)
    {
        if (c->getNome() == localAtual)
        {
            cidade = c;
            break;
        }
    }

    if (cidade == nullptr)
    {
        cout << "Cidade não encontrada." << endl;
        return;
    }

    // cria uma instancia de transporte
    Transporte* transporte = new Transporte(
        nome,
        tipo,
        capacidade,
        velocidade,
        distancia_entre_descansos,
        tempo_de_descanso,
        cidade
    );

    transportes.push_back(transporte);

    cout << "Transporte cadastrado com sucesso!" << endl;
}

void ControladorDeTransito::cadastrarPassageiro(string nome, string localAtual)
{
    Cidade* cidade = nullptr;

    // encontra o endereço de memória da cidade onde o transporte está situado baseado no nome informado
    // fazer uma função pra isso depois
    for (Cidade* c : cidades)
    {
        if (c->getNome() == localAtual)
        {
            cidade = c;
            break;
        }
    }

    if (cidade == nullptr)
    {
        cout << "Cidade não encontrada." << endl;
        return;
    }

    // cria uma instancia de passageiro
    Passageiro* passageiro = new Passageiro(
        nome,
        cidade
    );

    passageiros.push_back(passageiro);

    cout << "Passageiro cadastrado com sucesso!" << endl;
}

void ControladorDeTransito::iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino)
{
    Transporte* transporte = nullptr;

    Cidade* origem = nullptr;
    Cidade* destino = nullptr;

    vector<Passageiro*> passageirosSelecionados;

    // busca o transporte pelo nome
    for(Transporte* t : transportes){
        if(t->getNome() == nomeTransporte){

            transporte = t;
            break;
        }
    }

    //busca as cidades de origem e destino pelo nome
    for(Cidade* c : cidades){
        if(c->getNome() == nomeOrigem)
            origem = c;

        if(c->getNome() == nomeDestino)
            destino = c;
    }

    if(transporte == nullptr || origem == nullptr || destino == nullptr){
        cout << "Dados inválidos" << endl;
        return;
    }

    // testa se o transporte está na origem
    if(transporte->getLocalAtual() != origem){
        cout << "Transporte não está na cidade." << endl;
        return;
    }

    // busca passageiros, se o passageiro nao estiver na cidade de origem ele nao pode viajar
    for(string nome : nomesPassageiros){
        for(Passageiro* p : passageiros){
            if(p->getNome() == nome){
                if(p->getLocalAtual() != origem){
                    cout << "Passageiro fora da cidade." << endl;
                    return;
                }
                passageirosSelecionados.push_back(p);
            }
        }
    }

    if(passageirosSelecionados.size() > transporte->getCapacidade()){

        cout << "Capacidade excedida" << endl;
        return;
    }

    Trajeto* trajeto = buscarTrajeto(origem, destino);

    if(trajeto == nullptr){

        cout << "Trajeto não encontrado" << endl;
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

void ControladorDeTransito::relatarEstado()
{
    cout << "\n===== VIAGENS EM ANDAMENTO =====\n" << endl;

    bool encontrou = false;

    for (Viagem* v : viagens)
    {
        if (v->isEmAndamento())
        {
            v->relatarEstado();
            encontrou = true;
        }
    }

    if (!encontrou)
    {
        cout << "Nenhuma viagem em andamento." << endl;
    }

}

Trajeto *ControladorDeTransito::buscarTrajeto(Cidade *origem, Cidade *destino)
{
    for(Trajeto* t : trajetos){
        if(t->getOrigem() == origem && t->getDestino() == destino){
            return t;
        }
    }
    return nullptr;
}

void ControladorDeTransito::relatarPassageiros()
{
    cout << "======= RELATÓRIO DE PASSAGEIROS =======" << endl;
    for(Passageiro* p : passageiros){
        bool encontrou = false;
        for (Viagem* v : viagens)
        {
            if(!v->isEmAndamento()){
                continue;
            }

            for(Passageiro* vp : v->getPassageiros()){
                if(vp == p){
                    cout << p->getNome() << " - Em trânsito (" << v->getTrajeto()->getOrigem()->getNome() << " -> " << v->getTrajeto()->getDestino()->getNome() << ") - " << v->getTransporte()->getNome() << endl;

                    encontrou = true;
                    break;
                }
            }
            if(encontrou){
                break;
            }
        }
        if(!encontrou){
            cout << p->getNome() << " - Local atual: " << p->getLocalAtual()->getNome() << endl;
        }
    }
}
