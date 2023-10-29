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
    aux.chave = stoi(s.substr(0, pos));
    aux.dado1 = stoi(s.substr(pos + 1, s.length()));
    pos = s.find(delimiter, pos + 1);
    auxS = s.substr(pos + 1, s.length());
    strcpy(aux.dado2, auxS.c_str());
    return aux;
}

int main() {
    srand(static_cast<unsigned>(time(0))); 
    string linha, nomeArquivo;
    bool gerouTodas;
    int chaveAleatoria = 0;
    int totalPresente = 1;
    int totalAusente = 1;
    string vetorEncontradas[16];
    string vetorNaoEncontradas[16];
    char buffer[1000];

    nomeArquivo = "dadosDesordenados100.txt";
    ifstream arquivo("Arquivos Entrada/" + nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    Tiporeg *dados = new Tiporeg[100];
    int index = 0;

    while (getline(arquivo, linha)) {
        string linhaAux = linha;
        if (linhaAux != "") {
            dados[index] = retornaTipoReg(linha);
            index++;
        }
    }

    arquivo.close();

    while (!gerouTodas) {
        if (totalAusente < 15)
            chaveAleatoria = rand() % 20000;
        else
            chaveAleatoria = rand() % 10000;

        auto start_time = chrono::high_resolution_clock::now();

        bool chaveEncontrada = false;
        int comparacoes = 0; // Contador de comparações

        for (int i = 0; i < 100; i++) {
            comparacoes++; // Incrementa o contador a cada comparação
            if (dados[i].chave == chaveAleatoria) {
                chaveEncontrada = true;
                break;
            }
        }

        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_time = end_time - start_time;

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

    ofstream arquivo_saida("Arquivos Saida/sequencial/arquivo_saida_" + nomeArquivo);

    if (!arquivo_saida.is_open()) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
        return 1;
    }

    for (int i = 0; i < 15; i++)
        arquivo_saida << vetorEncontradas[i] << endl;

    for (int i = 0; i < 15; i++)
        arquivo_saida << vetorNaoEncontradas[i] << endl;

    arquivo_saida.close();

    delete[] dados;

    return 0;
}
