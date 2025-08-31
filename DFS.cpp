#include <iostream>
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

int* cor;
int* pai;
int* desc;
int* fi;
int tempo;

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

    // Se for grafo não-direcionado
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

void dfs_visit(Grafo* grafo, int u) {
    cor[u] = CINZA;
    tempo++;
    desc[u] = tempo;

    No* adj = grafo->lista[u];
    while (adj != nullptr) {
        int v = adj->valor;
        if (cor[v] == BRANCO) {
            pai[v] = u;
            dfs_visit(grafo, v);
        }
        adj = adj->prox;
    }

    cor[u] = PRETO;
    tempo++;
    fi[u] = tempo;
}

void dfs(Grafo* grafo, int origem) {
    int tamanho = grafo->tamanho;
    cor = new int[tamanho];
    desc = new int[tamanho];
    fi = new int[tamanho];
    pai = new int[tamanho];
    tempo = 0;

    for (int i = 0; i < tamanho; i++) {
        cor[i] = BRANCO;
        pai[i] = -1;
        desc[i] = -1;
        fi[i] = -1;
    }

    for (int i = 0; i < tamanho; i++) {
        if (cor[origem] == BRANCO) {
            dfs_visit(grafo, i);
        }
    }

    // Imprimir resultados:
    cout << "\nResultados DFS:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Vertice: " << i
             << ", Descoberta: " << desc[i]
             << ", Finalizacao: " << fi[i]
             << ", Pai: " << pai[i] << endl;
    }
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

    dfs(grafo, 0);

    return 0;
}