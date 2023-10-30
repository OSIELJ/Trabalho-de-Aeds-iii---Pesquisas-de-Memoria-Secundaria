# Trabalho Prático de Algoritmos e Estruturas de Dados III

Este é um trabalho prático desenvolvido para a disciplina de Algoritmos e Estruturas de Dados III. O projeto consiste em implementações de Árvore Binária, Árvore AVL e Pesquisa Sequencial, bem como um Gerador de Registros. Neste README, há o detalhamento do código de Pesquisa Sequencial.

## Conteúdo

1. [Gerador de Registros](#gerador-de-registros)
2. [Árvore Binária de Busca](#árvore-binária-de-busca)
3. [Árvore AVL](#árvore-avl)
4. [Pesquisa Sequencial](#pesquisa-sequencial)
5. [Observações Gerais](#observações-gerais)
6. [Autores](#autores)

## Gerador de Registros

O Gerador de Registros é responsável por criar registros aleatórios e escrevê-los em arquivos de dados ordenados e desordenados.

### Arquivo: `gerador_de_registros.cpp`

#### Estruturas de Dados

- **Registro**: Uma estrutura que representa um registro com três campos - chave (um número inteiro), dado1 (um número inteiro) e dado2 (uma string de 1000 caracteres).

#### Funções

- `gerarRegistroAleatorio(int chave)`: Gera um registro aleatório com uma chave específica e valores aleatórios para dado1 e dado2.

### Como Usar

1. Compile o código.
2. Execute o programa.
3. Os arquivos de dados ordenados e desordenados são gerados com base no número de registros propostos.

## Árvore Binária de Busca

A Árvore Binária de Busca é uma estrutura de dados que permite inserir, buscar e verificar a existência de chaves em uma árvore.

### Arquivo: `arvore_binaria.cpp`

#### Estruturas de Dados

- **Tiporeg**: Uma estrutura que representa um registro com três campos - chave (um número inteiro), dado1 (um número inteiro) e dado2 (uma string de 1000 caracteres).
- **No**: Uma estrutura que representa um nó em uma árvore binária, com um registro, ponteiros para os nós à esquerda e à direita e uma variável para contar o número de interações durante as operações.

#### Funções

- `novoNo(Tiporeg pRegistro)`: Cria um novo nó com um registro específico e retorna o ponteiro para esse nó.

### Como Usar

1. Compile o código.
2. Execute o programa.
3. O código lê um arquivo de dados desordenados, insere os registros em uma árvore binária e realiza buscas aleatórias.

## Árvore AVL

A Árvore AVL é uma árvore binária balanceada que mantém seu fator de equilíbrio.

### Arquivo: `arvore_avl.cpp`

#### Estruturas de Dados

- **Tiporeg**: Uma estrutura que representa um registro com três campos - chave (um número inteiro), dado1 (um número inteiro) e dado2 (uma string de 1000 caracteres).
- **No**: Uma estrutura que representa um nó em uma árvore AVL, com um registro, ponteiros para os nós à esquerda e à direita, uma variável para contar o número de interações durante as operações e uma variável para manter a altura do nó.

#### Funções

- `rotacaoDireita(No* y)`: Realiza uma rotação à direita em um nó da árvore AVL para manter o equilíbrio.
- `rotacaoEsquerda(No* x)`: Realiza uma rotação à esquerda em um nó da árvore AVL para manter o equilíbrio.
- `fatorBalanceamento(No* no)`: Calcula o fator de balanceamento de um nó (diferença entre a altura da subárvore esquerda e da subárvore direita).

### Como Usar

1. Compile o código.
2. Execute o programa.
3. O código lê um arquivo de dados ordenados, insere os registros em uma árvore AVL e realiza buscas aleatórias.

## Pesquisa Sequencial

O código de Pesquisa Sequencial realiza buscas sequenciais em registros utilizando chaves aleatórias.

### Arquivo: `pesquisa_sequencial.cpp`

#### Funcionalidades

- Gera chaves aleatórias e busca por elas nos registros.
- Registra o tempo de busca e o número de comparações realizadas.
- Armazena os resultados das buscas em arquivos de saída.

### Como Usar

1. Compile o código.
2. Execute o programa.
3. O código lê um arquivo de dados desordenados e realiza buscas sequenciais aleatórias.
4. Os resultados das buscas são registrados em arquivos de saída.

## Observações Gerais

- Certifique-se de que todos os arquivos de entrada necessários estejam presentes no diretório especificado no código.
- Os resultados das buscas são registrados em arquivos de saída correspondentes para posterior análise.

## Autores

- Daniel Rodrigues Pereira - daniel.pereira@ufvjm.edu.br
- Patricia Helen Ribeiro - patricia.helen@ufvjm.edu.br
- Fernando Maia - maia.fernando@ufvjm.edu.br
- Osiel Junior Martins Bicalho - osiel.junior@ufvjm.edu.br
- Raul Rodrigues - santos.raul@ufvjm.edu.br

Agora o README inclui informações sobre o código de Pesquisa Sequencial no projeto. Certifique-se de compilar e executar o código correspondente para obter resultados de busca sequencial.
