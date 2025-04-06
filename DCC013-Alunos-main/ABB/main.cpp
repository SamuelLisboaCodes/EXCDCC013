#include <iostream>
#include "ABB.h"

int main() {
    ABB arvore;
    int n, valor;

    std::cout << "Quantos valores deseja inserir na arvore? ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Digite o valor " << i + 1 << ": ";
        std::cin >> valor;
        arvore.insere(valor);
    }

    std::cout << "\n--- RESULTADOS ---\n";

    std::cout << "Soma: " << arvore.soma() << std::endl;
    std::cout << "Media: " << arvore.media() << std::endl;
    std::cout << "Eh cheia? " << (arvore.ehCheia() ? "Sim" : "Nao") << std::endl;
    std::cout << "Eh completa? " << (arvore.ehCompleta() ? "Sim" : "Nao") << std::endl;
    std::cout << "Eh estritamente binaria? " << (arvore.estritamenteBinaria() ? "Sim" : "Nao") << std::endl;

    int ref;
    std::cout << "Digite um valor de referencia para contar maiores que ele: ";
    std::cin >> ref;
    std::cout << "Maiores que " << ref << ": " << arvore.maioresQue(ref) << std::endl;

    int nivel;
    std::cout << "Digite um nivel para calcular a media: ";
    std::cin >> nivel;
    std::cout << "Media no nivel " << nivel << ": " << arvore.mediaNivel(nivel) << std::endl;

    int x, y;
    std::cout << "Digite o intervalo [x, y] para imprimir valores nesse intervalo:\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "Valores no intervalo [" << x << ", " << y << "]: ";
    arvore.imprimeIntervalo(x, y);
    std::cout << std::endl;

    std::cout << "Altura de cada no:" << std::endl;
    arvore.alturaNos();

    return 0;
}
