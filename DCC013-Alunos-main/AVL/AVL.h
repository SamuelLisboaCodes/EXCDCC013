#ifndef AVL_H
#define AVL_H

#include "NoAVL.h"

class AVL {
private:
    NoAVL* raiz;

public:
    AVL();
    ~AVL();

    void inserir(int valor);
    void remover(int valor);
    void imprimir();
    void imprimirOrdem();
};

#endif
