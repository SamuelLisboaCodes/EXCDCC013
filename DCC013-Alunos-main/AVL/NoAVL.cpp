#include "NoAVL.h"

NoAVL::NoAVL(int v) {
    valor = v;
    altura = 1;
    esq = dir = nullptr;
}

NoAVL::~NoAVL() {}

int NoAVL::getValor() { return valor; }
NoAVL* NoAVL::getEsq() { return esq; }
NoAVL* NoAVL::getDir() { return dir; }

int NoAVL::max(int a, int b) {
    return (a > b) ? a : b;
}

int NoAVL::getAltura(NoAVL* no) {
    return no ? no->altura : 0;
}

int NoAVL::getBalanceamento(NoAVL* no) {
    return no ? getAltura(no->esq) - getAltura(no->dir) : 0;
}

void NoAVL::atualizaAltura() {
    altura = 1 + max(getAltura(esq), getAltura(dir));
}

NoAVL* NoAVL::rotacaoDireita(NoAVL* y) {
    NoAVL* x = y->esq;
    NoAVL* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->atualizaAltura();
    x->atualizaAltura();

    return x;
}

NoAVL* NoAVL::rotacaoEsquerda(NoAVL* x) {
    NoAVL* y = x->dir;
    NoAVL* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->atualizaAltura();
    y->atualizaAltura();

    return y;
}

NoAVL* NoAVL::corrige(NoAVL* no) {
    no->atualizaAltura();
    int balance = getBalanceamento(no);

    // Rotação simples à direita
    if (balance > 1 && getBalanceamento(no->esq) >= 0)
        return rotacaoDireita(no);

    // Rotação dupla (esquerda-direita)
    if (balance > 1 && getBalanceamento(no->esq) < 0) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    // Rotação simples à esquerda
    if (balance < -1 && getBalanceamento(no->dir) <= 0)
        return rotacaoEsquerda(no);

    // Rotação dupla (direita-esquerda)
    if (balance < -1 && getBalanceamento(no->dir) > 0) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}

NoAVL* NoAVL::insere(NoAVL* no, int v) {
    if (!no)
        return new NoAVL(v);

    if (v < no->valor)
        no->esq = insere(no->esq, v);
    else if (v > no->valor)
        no->dir = insere(no->dir, v);
    else
        return no;

    return corrige(no);
}

NoAVL* NoAVL::menorValor(NoAVL* no) {
    NoAVL* atual = no;
    while (atual && atual->esq)
        atual = atual->esq;
    return atual;
}

NoAVL* NoAVL::remove(NoAVL* no, int v) {
    if (!no) return no;

    if (v < no->valor)
        no->esq = remove(no->esq, v);
    else if (v > no->valor)
        no->dir = remove(no->dir, v);
    else {
        if (!no->esq || !no->dir) {
            NoAVL* temp = no->esq ? no->esq : no->dir;
            if (!temp) {
                temp = no;
                no = nullptr;
            } else
                *no = *temp;
            delete temp;
        } else {
            NoAVL* temp = menorValor(no->dir);
            no->valor = temp->valor;
            no->dir = remove(no->dir, temp->valor);
        }
    }

    if (!no) return no;

    return corrige(no);
}

NoAVL* NoAVL::busca(int v) {
    if (v == valor)
        return this;
    else if (v < valor && esq)
        return esq->busca(v);
    else if (v > valor && dir)
        return dir->busca(v);
    return nullptr;
}

void NoAVL::imprimeVisualizacao(int nivel) {
    if (dir)
        dir->imprimeVisualizacao(nivel + 1);

    for (int i = 0; i < nivel; i++)
        cout << "   ";
    cout << valor << endl;

    if (esq)
        esq->imprimeVisualizacao(nivel + 1);
}

void NoAVL::imprimeOrdemCrescente() {
    if (esq)
        esq->imprimeOrdemCrescente();
    cout << valor << " ";
    if (dir)
        dir->imprimeOrdemCrescente();
}
