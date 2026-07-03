# Manual do Usuário

## Introdução

O Controlador de Viagens é um sistema que permite administrar cidades, trajetos, transportes, passageiros e viagens através de uma interface de linha de comando (CLI).

Ao iniciar o programa, todos os dados previamente salvos são carregados automaticamente.

---

## Menu Principal

O sistema apresenta o seguinte menu:

```
1 - Cadastrar cidade
2 - Cadastrar trajeto
3 - Cadastrar transporte
4 - Cadastrar passageiro
5 - Iniciar viagem
6 - Avançar horas
7 - Relatórios
0 - Salvar e sair
```

---

## Cadastro de Cidade

Permite cadastrar uma nova cidade.

Exemplo:

```
Nome da cidade:
Natal
```

---

## Cadastro de Trajeto

Permite cadastrar uma ligação entre duas cidades.

Informações solicitadas:

* Cidade de origem
* Cidade de destino
* Tipo do trajeto
* Distância

---

## Cadastro de Transporte

Permite cadastrar um novo transporte.

Informações solicitadas:

* Nome
* Tipo
* Capacidade
* Velocidade
* Distância entre descansos
* Tempo de descanso
* Cidade onde se encontra

---

## Cadastro de Passageiro

Permite cadastrar um passageiro.

Informações solicitadas:

* Nome
* Cidade atual

---

## Iniciar Viagem

Permite iniciar uma viagem utilizando um transporte previamente cadastrado.

São solicitados:

* Transporte
* Cidade de origem
* Cidade de destino
* Quantidade de passageiros
* Nome de cada passageiro

---

## Avançar Horas

Avança o relógio da simulação.

Quando o tempo necessário para uma viagem é concluído:

* o transporte chega ao destino;
* os passageiros chegam ao destino;
* a cidade de destino registra uma nova visita.

---

## Relatórios

O sistema apresenta:

* Localização dos passageiros;
* Localização dos transportes;
* Viagens em andamento;
* Ranking das cidades mais visitadas.

---

## Persistência

Ao escolher a opção **0 - Salvar e sair**, o sistema grava automaticamente:

* cidades;
* trajetos;
* transportes;
* passageiros.

As viagens em andamento não são salvas.

---

## Recomendações

Para evitar erros, recomenda-se seguir a seguinte ordem de utilização:

1. Cadastrar cidades;
2. Cadastrar trajetos;
3. Cadastrar transportes;
4. Cadastrar passageiros;
5. Iniciar viagens;
6. Avançar horas;
7. Consultar relatórios.
