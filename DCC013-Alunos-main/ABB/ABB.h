#ifndef ABB_H
#define ABB_H

#include "NoABB.h"
#include <iostream>
using namespace std;

class ABB {
private:
    NoABB* raiz;
    int somaRec(NoABB* no);
    int contaNos(NoABB* no);
    bool cheia(NoABB* no);
    bool completa(NoABB* no, int index, int total);
    void imprimeIntervaloRec(NoABB* no, int x, int y);
    bool estritamenteBinariaRec(NoABB* no);
    int maioresQueRec(NoABB* no, int v);
    void mediaNivelRec(NoABB* no, int nivel, int atual, int& soma, int& cont);
    int alturaNosRec(NoABB* no);
    void atualizaAltura(NoABB* no);

public:
    ABB();
    void insere(int v);
    int soma();
    float media();
    bool ehCheia();
    bool ehCompleta();
    void imprimeIntervalo(int x, int y);
    bool estritamenteBinaria();
    int maioresQue(int v);
    float mediaNivel(int nivel);
    void alturaNos();
    int calcularAltura(NoABB* no);
};

#endif