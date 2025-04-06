#include "ABB.h"
#include <cmath>

ABB::ABB() {
    raiz = nullptr;
}

void ABB::insere(int v) {
    raiz = raiz ? raiz->insere(raiz, v) : new NoABB(v);
}

int ABB::somaRec(NoABB* no) {
    if (!no) return 0;
    return no->valor + somaRec(no->esq) + somaRec(no->dir);
}

int ABB::soma() {
    return somaRec(raiz);
}

int ABB::contaNos(NoABB* no) {
    if (!no) return 0;
    return 1 + contaNos(no->esq) + contaNos(no->dir);
}

float ABB::media() {
    int total = contaNos(raiz);
    return total ? (float)somaRec(raiz) / total : 0;
}

bool ABB::cheia(NoABB* no) {
    if (!no) return true;
    if (!no->esq && !no->dir) return true;
    if (no->esq && no->dir)
        return cheia(no->esq) && cheia(no->dir);
    return false;
}

bool ABB::ehCheia() {
    return cheia(raiz);
}

bool ABB::completa(NoABB* no, int index, int total) {
    if (!no) return true;
    if (index >= total) return false;
    return completa(no->esq, 2 * index + 1, total) && completa(no->dir, 2 * index + 2, total);
}

bool ABB::ehCompleta() {
    int total = contaNos(raiz);
    return completa(raiz, 0, total);
}

void ABB::imprimeIntervaloRec(NoABB* no, int x, int y) {
    if (!no) return;
    if (x < no->valor) imprimeIntervaloRec(no->esq, x, y);
    if (x <= no->valor && no->valor <= y) cout << no->valor << " ";
    if (y > no->valor) imprimeIntervaloRec(no->dir, x, y);
}

void ABB::imprimeIntervalo(int x, int y) {
    imprimeIntervaloRec(raiz, x, y);
}

bool ABB::estritamenteBinariaRec(NoABB* no) {
    if (!no) return true;
    if (!no->esq && !no->dir) return true;
    if (no->esq && no->dir)
        return estritamenteBinariaRec(no->esq) && estritamenteBinariaRec(no->dir);
    return false;
}

bool ABB::estritamenteBinaria() {
    return estritamenteBinariaRec(raiz);
}

int ABB::maioresQueRec(NoABB* no, int v) {
    if (!no) return 0;
    int cont = (no->valor > v) ? 1 : 0;
    return cont + maioresQueRec(no->esq, v) + maioresQueRec(no->dir, v);
}

int ABB::maioresQue(int v) {
    return maioresQueRec(raiz, v);
}

void ABB::mediaNivelRec(NoABB* no, int nivel, int atual, int& soma, int& cont) {
    if (!no) return;
    if (atual == nivel) {
        soma += no->valor;
        cont++;
    } else {
        mediaNivelRec(no->esq, nivel, atual + 1, soma, cont);
        mediaNivelRec(no->dir, nivel, atual + 1, soma, cont);
    }
}

float ABB::mediaNivel(int nivel) {
    int soma = 0, cont = 0;
    mediaNivelRec(raiz, nivel, 0, soma, cont);
    return cont ? (float)soma / cont : 0;
}

int ABB::alturaNosRec(NoABB* no) {
    if (!no) return -1;
    int he = alturaNosRec(no->esq);
    int hd = alturaNosRec(no->dir);
    no->altura = std::max(he, hd) + 1;
    return no->altura;
}

void ABB::alturaNos() {
    calcularAltura(raiz);
}

int ABB::calcularAltura(NoABB* no) {
    if (!no)
        return -1;  // altura de nó nulo é -1

    int alturaEsq = calcularAltura(no->esq);
    int alturaDir = calcularAltura(no->dir);
    
    no->altura = std::max(alturaEsq, alturaDir) + 1;

    std::cout << "Valor: " << no->valor << " | Altura: " << no->altura << std::endl;

    return no->altura;
}
