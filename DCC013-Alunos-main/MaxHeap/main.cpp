#include <iostream>
#include <string>
#include "MaxHeap.h"

using namespace std;

int lerNumero() {
    string s;
    getline(cin, s);
    int x = 0;
    int n = s.length();
    if (n == 0 || n > 6)
        return -100000;
    for (int i = ((s[0] == '-') ? 1 : 0); i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            x = x * 10 + s[i] - '0';
        else
            return -100000;
    }
    if (s[0] == '-')
        x *= -1;
    return x;
}

int filtrarEntrada() {
    int n = lerNumero();
    while (n == -100000) {
        cout << "Numero invalido. Tente novamente: ";
        n = lerNumero();
    }
    return n;
}

int main() {
    MaxHeap* heap = new MaxHeap();

    // Questão 1: inserção de valores
    int entrada[] = {32, 11, 15, 20, 76, 23, 17, 50, 33, 80};
    for (int i = 0; i < 10; i++)
        heap->insere(entrada[i]);

    int op = 0;
    vector<int> v;
    while (true) {
        cout << "\033[2J\033[1;1H";
        cout << "Selecione uma operacao:" << endl;
        cout << " 1: Inserir valor" << endl;
        cout << " 2: Olhar raiz" << endl;
        cout << " 3: Remover raiz" << endl;
        cout << " 4: Imprimir como lista" << endl;
        cout << " 5: Imprimir como arvore" << endl;
        cout << " 6: Heapsort" << endl;
        cout << " 7: Buscar valor na heap" << endl;
        cout << " 8: Verificar se vetor eh MinHeap" << endl;
        cout << " 9: Transformar vetor em MaxHeap" << endl;
        cout << "10: Encerrar" << endl;
        cout << "Digite o numero da operacao: ";
        op = lerNumero();

        switch (op) {
            case 1:
                cout << "Digite valor: ";
                heap->insere(filtrarEntrada());
                cout << "Pressione ENTER para continuar.";
                lerNumero();
                break;
            case 2:
                cout << "Raiz: " << heap->getRaiz() << ". Pressione ENTER.";
                lerNumero();
                break;
            case 3:
                heap->remove();
                cout << "Raiz removida. Pressione ENTER.";
                lerNumero();
                break;
            case 4:
                heap->imprimeLista();
                cout << "Pressione ENTER.";
                lerNumero();
                break;
            case 5:
                heap->imprimeArvore();
                cout << "Pressione ENTER.";
                lerNumero();
                break;
            case 6:
                v = heap->heapsort();
                for (int x : v)
                    cout << x << ", ";
                cout << "\b\b  " << endl << "Pressione ENTER.";
                lerNumero();
                break;
            case 7: {
                cout << "Digite o valor a buscar: ";
                int valor = filtrarEntrada();
                int indice = heap->buscaValor(valor);
                if (indice == -1)
                    cout << "Valor nao encontrado." << endl;
                else
                    cout << "Valor encontrado no indice: " << indice << endl;
                cout << "Pressione ENTER.";
                lerNumero();
                break;
            }
            case 8: {
                vector<int> vTeste = {1, 3, 6, 5, 9, 8};
                cout << "Vetor eh MinHeap? " << (MaxHeap::ehMinHeap(vTeste) ? "Sim" : "Nao") << endl;
                cout << "Pressione ENTER.";
                lerNumero();
                break;
            }
            case 9: {
                vector<int> vetor = {5, 10, 15, 20, 25, 30};
                MaxHeap::transformarEmMaxHeap(vetor);
                cout << "Vetor convertido para MaxHeap: ";
                for (int x : vetor)
                    cout << x << ", ";
                cout << "\b\b  " << endl << "Pressione ENTER.";
                lerNumero();
                break;
            }
            case 10:
                return 0;
        }
    }

    return 0;
}
