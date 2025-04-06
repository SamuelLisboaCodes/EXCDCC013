#include "NoABB.h"
#include <algorithm>

NoABB::NoABB(int v) {
    valor = v;
    esq = dir = nullptr;
    altura = 0;
}

NoABB* NoABB::insere(NoABB* no, int v) {
    if (no == nullptr) return new NoABB(v);
    if (v < no->valor) no->esq = insere(no->esq, v);
    else no->dir = insere(no->dir, v);
    return no;
}

NoABB* NoABB::busca(int v) {
    if (v == valor) return this;
    if (v < valor && esq) return esq->busca(v);
    if (v > valor && dir) return dir->busca(v);
    return nullptr;
}

NoABB* NoABB::remove(NoABB* no, int v) {
    if (!no) return nullptr;
    if (v < no->valor) no->esq = remove(no->esq, v);
    else if (v > no->valor) no->dir = remove(no->dir, v);
    else {
        if (!no->esq) {
            NoABB* temp = no->dir;
            delete no;
            return temp;
        }
        else if (!no->dir) {
            NoABB* temp = no->esq;
            delete no;
            return temp;
        }
        NoABB* temp = no->dir;
        while (temp->esq) temp = temp->esq;
        no->valor = temp->valor;
        no->dir = remove(no->dir, temp->valor);
    }
    return no;
}
