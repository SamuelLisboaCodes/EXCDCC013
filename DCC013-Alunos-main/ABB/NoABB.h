#ifndef NOABB_H
#define NOABB_H

class NoABB {
public:
    int valor;
    int altura;
    NoABB* esq;
    NoABB* dir;

    NoABB(int v);
    NoABB* insere(NoABB* no, int v);
    NoABB* busca(int v);
    NoABB* remove(NoABB* no, int v);
};

#endif
