#include <iostream>
#include "AVL.h"
using namespace std;

int main() {
    AVL arvore;

    cout << "Inserindo elementos na árvore AVL...\n";
    int valores[] = {30, 20, 40, 10, 25, 35, 50, 5, 15};

    for (int v : valores) {
        arvore.inserir(v);
        cout << "Inserido: " << v << endl;
        arvore.imprimir();
        cout << "------------------\n";
    }

    cout << "\nRemovendo elementos...\n";
    arvore.remover(40);
    cout << "Removido: 40\n";
    arvore.imprimir();

    arvore.remover(30);
    cout << "Removido: 30\n";
    arvore.imprimir();

    cout << "\nElementos em ordem crescente:\n";
    arvore.imprimirOrdem();

    return 0;
}
