#include <iostream>
#include "MaxHeap.h"

using namespace std;

MaxHeap::~MaxHeap() {
    v.resize(0);
}

bool MaxHeap::vazia() const {
    return v.empty();
}

void MaxHeap::insere(int valor) {
    v.push_back(valor);
    sobe(v.size() - 1);
}

int MaxHeap::getRaiz() const {
    return v[0];
}

void MaxHeap::remove() {
    int n = v.size();
    if (n > 0) {
        v[0] = v[n - 1];
        desce(0);
        v.pop_back();
    }
}

void MaxHeap::imprimeLista() const {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << "\b\b  " << endl;
}

void MaxHeap::imprimeArvore() const {
    if (!v.empty())
        imprimeArvoreAux(0, v.size(), 0);
}

vector<int> MaxHeap::heapsort() const {
    vector<int> v2(v);
    for (int i = v2.size() - 1; i > 0; i--) {
        swap(v2[0], v2[i]);
        int j = 0, k = 1;
        while (j < i && k < i) {
            if (k + 1 < i && v2[k] < v2[k + 1]) k++;
            if (v2[j] < v2[k]) {
                swap(v2[j], v2[k]);
                j = k;
                k = 2 * j + 1;
            } else {
                break;
            }
        }
    }
    return v2;
}

void MaxHeap::imprimeArvoreAux(int i, int n, int altura) const {
    for (int j = 0; j < altura; j++)
        cout << "--";
    cout << "(" << v[i] << ")" << endl;
    int filho = 2 * i + 1;
    if (filho < n)
        imprimeArvoreAux(filho, n, altura + 1);
    if (++filho < n)
        imprimeArvoreAux(filho, n, altura + 1);
}

void MaxHeap::sobe(int i) {
    int pai = (i - 1) / 2;
    if (i > 0 && v[i] > v[pai]) {
        swap(v[i], v[pai]);
        sobe(pai);
    }
}

void MaxHeap::desce(int i) {
    int filho = 2 * i + 1;
    int n = v.size();
    if (filho < n) {
        if (filho + 1 < n && v[filho] < v[filho + 1])
            filho++;
        if (v[i] < v[filho]) {
            swap(v[i], v[filho]);
            desce(filho);
        }
    }
}

int MaxHeap::buscaValor(int valor) const {
    return buscaRecursiva(valor, 0);
}

int MaxHeap::buscaRecursiva(int valor, int i) const {
    int n = v.size();
    if (i >= n || v[i] < valor)
        return -1;

    if (v[i] == valor)
        return i;

    int filhoEsq = buscaRecursiva(valor, 2 * i + 1);
    if (filhoEsq != -1)
        return filhoEsq;

    return buscaRecursiva(valor, 2 * i + 2);
}

bool MaxHeap::ehMinHeap(const vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int esq = 2 * i + 1, dir = 2 * i + 2;
        if (esq < n && vetor[i] > vetor[esq])
            return false;
        if (dir < n && vetor[i] > vetor[dir])
            return false;
    }
    return true;
}

void MaxHeap::transformarEmMaxHeap(vector<int>& vetor) {
    int n = vetor.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        int pai = i;
        while (2 * pai + 1 < n) {
            int maiorFilho = 2 * pai + 1;
            if (maiorFilho + 1 < n && vetor[maiorFilho + 1] > vetor[maiorFilho])
                maiorFilho++;
            if (vetor[pai] < vetor[maiorFilho]) {
                swap(vetor[pai], vetor[maiorFilho]);
                pai = maiorFilho;
            } else {
                break;
            }
        }
    }
}
