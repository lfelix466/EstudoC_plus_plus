#include <iostream>
#include <queue>
using namespace std;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

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

void dfs(Grafo* grafo, int origem) {
    


}

int main() {
    Grafo* grafo = Graph(10);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 2, 4);
    adicionarAresta(grafo, 4, 5);
    adicionarAresta(grafo, 4, 6);
    adicionarAresta(grafo, 5, 7);
    adicionarAresta(grafo, 6, 7);
    adicionarAresta(grafo, 8, 9);

    //imprimirGrafo(grafo);
    dfs(grafo, 0);

    return 0;
}
