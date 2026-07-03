# Controlador de Viagens

## Descrição

O Controlador de Viagens é um sistema desenvolvido em C++ para a disciplina de Linguagem de Programação I.

O objetivo do sistema é gerenciar cidades, trajetos, transportes, passageiros e viagens entre cidades, permitindo simular deslocamentos e acompanhar o estado atual do sistema.

O projeto foi desenvolvido utilizando os conceitos de Programação Orientada a Objetos (POO), persistência de dados em arquivos texto e interface de linha de comando (CLI).

---

## Funcionalidades

O sistema permite:

* Cadastrar cidades;
* Cadastrar trajetos entre cidades;
* Cadastrar transportes;
* Cadastrar passageiros;
* Iniciar viagens;
* Avançar o tempo da simulação;
* Consultar relatórios do sistema;
* Salvar e carregar automaticamente os dados.

---

## Estrutura do Projeto

```
Projeto/
│
├── include/
│   ├── Cidade.h
│   ├── Passageiro.h
│   ├── Trajeto.h
│   ├── Transporte.h
│   ├── Viagem.h
│   └── ControladorDeTransito.h
│
├── src/
│   ├── Cidade.cpp
│   ├── Passageiro.cpp
│   ├── Trajeto.cpp
│   ├── Transporte.cpp
│   ├── Viagem.cpp
│   ├── ControladorDeTransito.cpp
│   └── main.cpp
│
├── data/
    ├── cidades.txt
    ├── trajetos.txt
    ├── transportes.txt
    └── passageiros.txt

```

---

## Persistência de Dados

Os seguintes dados são armazenados automaticamente em arquivos texto:

* Cidades
* Trajetos
* Transportes
* Passageiros

As viagens em andamento não são persistidas. Caso o programa seja encerrado, será necessário iniciar novamente as viagens.

---

## Compilação

Utilizando o compilador g++:

```
g++ src/*.cpp -Iinclude -o sistema
```

No Windows:

```
g++ src\*.cpp -Iinclude -o sistema.exe
```

---

## Execução

Linux:

```
./sistema
```

Windows:

```
.\sistema.exe
```

---

## Tecnologias utilizadas

* C++
* Programação Orientada a Objetos
* STL (vector, string)
* ifstream
* ofstream
* sstream
* stringstream

---

## Autor

Lorenna Mirely de Sousa Silva
