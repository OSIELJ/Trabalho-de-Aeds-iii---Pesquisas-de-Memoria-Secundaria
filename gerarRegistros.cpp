#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Registro {
    int chave;
    int dado1;
    char dado2[1000];
};

struct No {
    int chave;
    No* antecessor;
    No* sucessor;
};


Registro gerarRegistroAleatorio(int chave) {
    Registro novoRegistro;
    novoRegistro.chave = chave;
    novoRegistro.dado1 = rand() % 1000;
    for (int i = 0; i < 1000; i++) {
        novoRegistro.dado2[i] = 'A' + rand() % 26;
    }
    return novoRegistro;
}

int main() {

    int numeroDeRegistroProposto = 100;

 for (int i = 1; i <= 5; i++)
 {
    srand(static_cast<unsigned>(time(0)));

    ofstream arquivo("dadosOrdenados"+to_string(numeroDeRegistroProposto)+".txt");
    ofstream arquivoR("dadosDesordenados"+to_string(numeroDeRegistroProposto)+".txt");

    if (!arquivo.is_open() && arquivoR.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return 1;
    }

    for (int chave = 1; chave <= numeroDeRegistroProposto; chave++) {
        Registro registro = gerarRegistroAleatorio(chave);

        arquivo << registro.chave << ";" << registro.dado1 << ";" << registro.dado2 << endl;
        cout << "chave: " << registro.chave << " dado1: " << registro.dado1
        << " dado2: " << registro.dado2;

        arquivoR << registro.chave + rand() % 1000 << ";" << registro.dado1 << ";" << registro.dado2 << endl;
        cout << "chave: " << registro.chave << " dado1: " << registro.dado1
        << " dado2: " << registro.dado2;


    }

    switch (numeroDeRegistroProposto)
    {
    case 100:
        numeroDeRegistroProposto = 500;
        break;
    case 500:
        numeroDeRegistroProposto = 1000;
        break;
    case 1000:
        numeroDeRegistroProposto = 5000;
        break;

    case 5000:
        numeroDeRegistroProposto = 10000;
        break;
    }

 }    
}