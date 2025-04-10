#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> v;
    void sobe(int i);
    void desce(int i);
    void imprimeArvoreAux(int i, int n, int altura) const;
    int buscaRecursiva(int valor, int i) const;

public:
    MaxHeap() {};
    ~MaxHeap();

    bool vazia() const;
    int getRaiz() const;
    void insere(int valor);
    void remove();
    void imprimeLista() const;
    void imprimeArvore() const;
    vector<int> heapsort() const;
    int buscaValor(int valor) const;
    
    static bool ehMinHeap(const vector<int>& vetor);
    static void transformarEmMaxHeap(vector<int>& vetor);
};

#endif
