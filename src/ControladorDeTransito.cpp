/* Classe responsável por ser a ponte entre as outras classes.
 * O Controlador de Transito possui uma lista das cidades, trajetos, transportes, passageiros e viagens existentes no sistema. ALém de poder cadastrá-los, ele é responsável por gerenciar as viagens. 
*/

#include "ControladorDeTransito.h"

void ControladorDeTransito::salvarDados()
{
    salvarCidades();
    salvarTrajetos();
    salvarTransportes();
    salvarPassageiros();
}

void ControladorDeTransito::carregarDados()
{
    cout << "carregando cidades..." << endl;
    carregarCidades();    

    cout << "carregando trajetos..." << endl;
    carregarTrajetos();
    
    cout << "carregando transportes..." << endl;
    carregarTransportes();
    
    cout << "carregando passageiros..." << endl;
    carregarPassageiros();
}

void ControladorDeTransito::cadastrarCidade(string nome)
{
    for (Cidade* c : cidades)
    {
        if (c->getNome() == nome){
            return;
        }
    }
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

    for(Trajeto* t : trajetos)
    {
        if(t->getOrigem() == origem && t->getDestino() == destino)
        {
            return;
        }
    }
    trajetos.push_back(trajeto);
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

    for (Transporte* t : transportes)
    {
        if (t->getNome() == nome)
        {
            return;
        }
    }
    transportes.push_back(transporte);
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

    for (Passageiro* p : passageiros)
    {
        if (p->getNome() == nome)
        {
            return;
        }
    }

    passageiros.push_back(passageiro);
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
    cout << "\n===== SITUAÇÃO ATUAL DO SISTEMA =====\n" << endl;
    
    relatarPassageiros();
    
    relatarTransportes();
    
    relatarViagens();
    
    relatarCidadesMaisVisitadas();
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

void ControladorDeTransito::relatarTransportes()
{
    cout << "======= RELATÓRIO DE TRANSPORTES =======" << endl;

    for(Transporte* t : transportes)
    {
        bool encontrou = false;

        for(Viagem* v : viagens)
        {
            if(v->isEmAndamento() && v->getTransporte() == t){
                 cout << t->getNome() << " - Em trânsito (" << v->getTrajeto()->getOrigem()->getNome() << " -> "<< v->getTrajeto()->getDestino()->getNome() << ")" << endl;

                encontrou = true;
                break;
            }
        }

        if(!encontrou){
            cout << t->getNome() << " - " << t->getLocalAtual()->getNome() << endl;
        }
    }
}

void ControladorDeTransito::relatarViagens()
{
    cout << "======= RELATÓRIO DE VIAGENS =======" << endl;

    bool encontrou = false;

    for(Viagem* v : viagens)
    {
        if(v->isEmAndamento())
        {
            v->relatarEstado();
            encontrou = true;
        }
    }

    if(!encontrou)
        cout << "Nenhuma viagem em andamento.\n";
}

void ControladorDeTransito::relatarCidadesMaisVisitadas()
{
    cout << "======= RELATÓRIO DE CIDADES MAIS VISITADAS =======" << endl;

    for(Cidade* c : cidades)
    {
        cout << c->getNome() << " - " << c->getVisitas() << " visitas" << endl;
    }
}







void ControladorDeTransito::salvarCidades()
{
    ofstream arquivo("data/cidades.txt");
    for(Cidade* c : cidades)
    {
        arquivo << c->getNome() << ";" << c->getVisitas() << endl;
    }
    arquivo.close();
}

void ControladorDeTransito::carregarCidades()
{
    ifstream arquivo("data/cidades.txt");

    if(!arquivo.is_open())
    {
        cout << "Arquivo de cidades não encontrado." << endl;
        return;
    }

    string linha;

    while(getline(arquivo, linha))
    {
        cout << "linha lida: " << linha << endl;

        stringstream ss(linha);

        string nome;
        getline(ss, nome, ';');

        int visitas;
        ss >> visitas;

        cout << "nome: " << nome << ", visitas: " << visitas << endl;

        cadastrarCidade(nome);

        for(Cidade* c : cidades)
        {
            if(c->getNome() == nome)
            {
                c->setVisitas(visitas);
                break;
            }
        }
        cout << "Cidade carregada: " << nome << ", visitas: " << visitas << endl;
    }

    arquivo.close();
}

void ControladorDeTransito::salvarTrajetos()
{
    ofstream arquivo("data/trajetos.txt");

    for(Trajeto* t : trajetos)
    {  
        arquivo << t->getOrigem()->getNome() << ";" << t->getDestino()->getNome() << ";" << t->getTipo() << ";" << t->getDistancia() << endl;
    }
    arquivo.close();
}

void ControladorDeTransito::carregarTrajetos()
{
    ifstream arquivo("data/trajetos.txt");

    if(!arquivo.is_open())
    {
        cout << "Arquivo de trajetos não encontrado." << endl;
        return;
    }

    string origem, destino;
    string linha;

    while(getline(arquivo, linha))
    {
        stringstream ss(linha);

        getline(ss, origem, ';');
        getline(ss, destino, ';');
        
        char tipo;
        ss >> tipo;

        ss.ignore(); // Ignora o ponto e vírgula

        int distancia;
        ss >> distancia;

        cadastrarTrajeto(origem, destino, tipo, distancia);

        cout << "Trajeto carregado: " << origem << " -> " << destino << ", tipo: " << tipo << ", distancia: " << distancia << endl;
    }
    arquivo.close();
}

void ControladorDeTransito::salvarTransportes()
{
    ofstream arquivo("data/transportes.txt");

    for (Transporte* t : transportes)
    {
        arquivo 
        << t->getNome() 
        << ";" << t->getTipo() << ";" 
        << t->getCapacidade() << ";" 
        << t->getVelocidade() << ";" 
        << t->getDistanciaEntreDescansos() << ";" 
        << t->getTempoDescanso() << ";" 
        << t->getLocalAtual()->getNome() 
        << endl;
    }
    arquivo.close();
}

void ControladorDeTransito::carregarTransportes()
{
    ifstream arquivo("data/transportes.txt");

    if(!arquivo.is_open())
    {
        cout << "Arquivo de transportes não encontrado." << endl;
        return;
    }

    string linha;
    while(getline(arquivo, linha))
    {
        stringstream ss(linha);

        string nome;
        getline(ss, nome, ';');

        char tipo;
        ss >> tipo;

        ss.ignore(); // Ignora o ponto e vírgula

        int capacidade;
        ss >> capacidade;

        ss.ignore(); // Ignora o ponto e vírgula

        int velocidade;
        ss >> velocidade;

        ss.ignore(); // Ignora o ponto e vírgula

        int distancia_entre_descansos;
        ss >> distancia_entre_descansos;

        ss.ignore(); // Ignora o ponto e vírgula

        int tempo_de_descanso;
        ss >> tempo_de_descanso;

        ss.ignore(); // Ignora o ponto e vírgula

        string local_atual;
        getline(ss, local_atual);

        cadastrarTransporte(nome, tipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, local_atual);

        cout << "Transporte carregado: " << nome << ", tipo: " << tipo << ", capacidade: " << capacidade << ", velocidade: " << velocidade << ", distancia entre descansos: " << distancia_entre_descansos << ", tempo de descanso: " << tempo_de_descanso << ", local atual: " << local_atual << endl;
    }
    arquivo.close();
}

void ControladorDeTransito::salvarPassageiros()
{
    ofstream arquivo("data/passageiros.txt");

    for (Passageiro* p : passageiros)
    {
        arquivo << p->getNome() << ";" << p->getLocalAtual()->getNome() << endl;
    }
    arquivo.close();
}

void ControladorDeTransito::carregarPassageiros()
{
    ifstream arquivo("data/passageiros.txt");

    if(!arquivo.is_open())
    {
        cout << "Arquivo de passageiros não encontrado." << endl;
        return;
    }

    string linha;
    while(getline(arquivo, linha))
    {
        stringstream ss(linha);

        string nome;
        getline(ss, nome, ';');

        string local_atual;
        getline(ss, local_atual);

        cadastrarPassageiro(nome, local_atual);

        cout << "Passageiro carregado: " << nome << ", local atual: " << local_atual << endl;
    }
    arquivo.close();
}
