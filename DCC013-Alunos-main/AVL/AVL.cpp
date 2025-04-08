#include "AVL.h"
#include <iostream>
using namespace std;

AVL::AVL() {
    raiz = nullptr;
}

AVL::~AVL() {
    // Destruir todos os nós da árvore (recursivamente, se quiser adicionar)
}

void AVL::inserir(int valor) {
    if (raiz)
        raiz = raiz->insere(raiz, valor);
    else
        raiz = new NoAVL(valor);
}

void AVL::remover(int valor) {
    if (raiz)
        raiz = raiz->remove(raiz, valor);
}

void AVL::imprimir() {
    if (raiz)
        raiz->imprimeVisualizacao(0);
    else
        cout << "Árvore vazia." << endl;
}

void AVL::imprimirOrdem() {
    if (raiz)
        raiz->imprimeOrdemCrescente();
    else
        cout << "Árvore vazia." << endl;
    cout << endl;
}
