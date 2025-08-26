#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

struct Grafo {
    int tamanho;
    No** lista;
};

Grafo* Graph(int num) {
    Grafo* grafo = new Grafo();
    grafo->tamanho = num;
    grafo->lista = new No*[num];
    for (int i = 0; i < num; i++) {
        grafo->lista[i] = nullptr;
    }
    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino) {
    No* novoNo = new No();
    novoNo->valor = destino;
    novoNo->prox = grafo->lista[origem];
    grafo->lista[origem] = novoNo;

    // Se for grafo não-direcionado, adicione o inverso também:
    novoNo = new No();
    novoNo->valor = origem;
    novoNo->prox = grafo->lista[destino];
    grafo->lista[destino] = novoNo;
}

void imprimirGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->tamanho; i++) {
        cout << "Vértice " << i << ":";
        No* temp = grafo->lista[i];
        while (temp != nullptr) {
            cout << " -> " << temp->valor;
            temp = temp->prox;
        }
        cout << endl;
    }
}

int main() {
    Grafo* grafo = Graph(5);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);

    imprimirGrafo(grafo);

    return 0;
}
