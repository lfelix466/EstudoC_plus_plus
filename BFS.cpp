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

void bfs(Grafo* grafo, int origem) {
    int tamanho = grafo->tamanho;
    int* cor = new int[tamanho];
    int* dis = new int[tamanho];
    int* pai = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        cor[i] = BRANCO;
        dis[i] = -1;
        pai[i] = -1;
    }

    cor[origem] = CINZA;
    dis[origem] = 0;

    queue<int> fila;
    fila.push(origem);

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        No* adj = grafo->lista[u];

        while (adj != nullptr) {
            int v = adj->valor;

            if (cor[v] == BRANCO) {
                cor[v] = CINZA;
                dis[v] = dis[u] + 1;
                pai[v] = u;
                fila.push(v);
            }

            adj = adj->prox; 
        }

        cor[u] = PRETO;
    }

    cout << "\nResultados da BFS a partir do vertice " << origem << ":\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Vertice " << i << ": distancia = " << dis[i];
        if (pai[i] != -1)
            cout << ", pai = " << pai[i];
        cout << endl;
    }

    delete[] cor;
    delete[] dis;
    delete[] pai;
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
    bfs(grafo, 0);

    return 0;
}
