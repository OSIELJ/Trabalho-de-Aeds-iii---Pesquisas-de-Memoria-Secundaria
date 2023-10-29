#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <cstring>
using namespace std;

struct Tiporeg
{
    int chave;
    int dado1;
    char dado2[1000];
};

Tiporeg retornaTipoReg(string s) {
    Tiporeg aux;
    string auxS = s;
    string delimiter = ";";
    int pos = s.find(delimiter);

    // Extrai a chave da string e a converte para um inteiro
    aux.chave = stoi(s.substr(0, pos));

    // Extrai o dado1 da string e o converte para um inteiro
    aux.dado1 = stoi(s.substr(pos + 1, s.length()));
    
    // Encontra a próxima posição do delimitador
    pos = s.find(delimiter, pos + 1);
    
    // Extrai o dado2 da string e copia-o para o campo 'dado2' da estrutura
    auxS = s.substr(pos + 1, s.length());
    strcpy(aux.dado2, auxS.c_str());
    
    return aux;
}

int main() {
    srand(static_cast<unsigned>(time(0));  // Inicializa o gerador de números aleatórios

    string linha, nomeArquivo;
    bool gerouTodas;
    int chaveAleatoria = 0;
    int totalPresente = 1;
    int totalAusente = 1;
    string vetorEncontradas[16];
    string vetorNaoEncontradas[16];
    char buffer[1000];

    nomeArquivo = "dadosDesordenados100.txt";  // Nome do arquivo de entrada
    ifstream arquivo("Arquivos Entrada/" + nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;  // Exibe uma mensagem de erro se a abertura falhar
        return 1;  // Encerra o programa com código de erro
    }

    Tiporeg *dados = new Tiporeg[100];  // Aloca dinamicamente memória para um array de estruturas
    int index = 0;

    while (getline(arquivo, linha)) {
        string linhaAux = linha;
        if (linhaAux != "") {
            dados[index] = retornaTipoReg(linha);  // Converte a linha em uma estrutura e armazena no array
            index++;
        }
    }

    arquivo.close();  // Fecha o arquivo de entrada

    while (!gerouTodas) {
        if (totalAusente < 15)
            chaveAleatoria = rand() % 20000;
        else
            chaveAleatoria = rand() % 10000;

        auto start_time = chrono::high_resolution_clock::now();  // Marca o início do cronômetro

        bool chaveEncontrada = false;
        int comparacoes = 0;  // Contador de comparações

        for (int i = 0; i < 100; i++) {
            comparacoes++;  // Incrementa o contador a cada comparação
            if (dados[i].chave == chaveAleatoria) {
                chaveEncontrada = true;
                break;
            }
        }

        auto end_time = chrono::high_resolution_clock::now();  // Marca o final do cronômetro
        chrono::duration<double> elapsed_time = end_time - start_time;  // Calcula o tempo decorrido

        if (chaveEncontrada) {
            if (totalPresente <= 15) {
                sprintf(buffer, "Chave (%.6d) encontrada na coleção. Tempo de busca: %.9f segundos. Número de comparações: %d", chaveAleatoria, elapsed_time.count(), comparacoes);
                vetorEncontradas[totalPresente - 1] = buffer;
                totalPresente++;
            }
        } else {
            if (totalAusente <= 15) {
                sprintf(buffer, "Chave (%.6d) não encontrada na coleção. Tempo de busca: %.9f segundos. Número de comparações: %d", chaveAleatoria, elapsed_time.count(), comparacoes);
                vetorNaoEncontradas[totalAusente - 1] = buffer;
                totalAusente++;
            }
        }

        gerouTodas = ((totalAusente == 16) && (totalPresente == 16));
    }

    ofstream arquivo_saida("Arquivos Saida/sequencial/arquivo_saida_" + nomeArquivo);  // Abre arquivo de saída

    if (!arquivo_saida.is_open()) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;  // Exibe mensagem de erro se a abertura do arquivo de saída falhar
        return 1;  // Encerra o programa com código de erro
    }

    for (int i = 0; i < 15; i++)
        arquivo_saida << vetorEncontradas[i] << endl;  // Escreve resultados das chaves encontradas

    for (int i = 0; i < 15; i++)
        arquivo_saida << vetorNaoEncontradas[i] << endl;  // Escreve resultados das chaves não encontradas

    arquivo_saida.close();  // Fecha o arquivo de saída

    delete[] dados;  // Libera a memória alocada dinamicamente

    return 0;  // Encerra o programa com sucesso
}
