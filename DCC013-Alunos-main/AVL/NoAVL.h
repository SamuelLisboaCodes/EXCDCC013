#ifndef NOAVL_H
#define NOAVL_H

#include <iostream>
using namespace std;

class NoAVL {
private:
    int valor;
    int altura;
    NoAVL* esq;
    NoAVL* dir;

    NoAVL* rotacaoDireita(NoAVL* y);
    NoAVL* rotacaoEsquerda(NoAVL* x);
    NoAVL* corrige(NoAVL* no);
    int max(int a, int b);

public:
    NoAVL(int v);
    ~NoAVL();

    int getValor();
    NoAVL* getEsq();
    NoAVL* getDir();

    int getAltura(NoAVL* no);
    int getBalanceamento(NoAVL* no);
    void atualizaAltura();

    NoAVL* insere(NoAVL* no, int valor);
    NoAVL* remove(NoAVL* no, int valor);
    NoAVL* menorValor(NoAVL* no);
    NoAVL* busca(int valor);
    void imprimeVisualizacao(int nivel);
    void imprimeOrdemCrescente();
};

#endif
