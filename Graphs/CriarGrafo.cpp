#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

Node* createGraph() {
    // Criar 4 nós (indexados de 0 a 3, mas val será 1 a 4)
    vector<Node*> nodes;
    for (int i = 1; i <= 4; i++) {
        nodes.push_back(new Node(i));
    }

    // Lista de adjacência
    vector<vector<int>> adjList = {
        {2, 4}, // Nó 1
        {1, 3}, // Nó 2
        {2, 4}, // Nó 3
        {1, 3}  // Nó 4
    };

    // Conectar os vizinhos
    for (size_t i = 0; i < adjList.size(); i++) {
        for (int neighbor : adjList[i]) {
            nodes[i]->neighbors.push_back(nodes[neighbor - 1]); // -1 pq vetor começa em 0
        }
    }

    // Retorna o nó inicial (nó 1)
    return nodes[0];
}

// Função para percorrer e imprimir o grafo usando BFS
void printGraph(Node* start) {
    unordered_map<Node*, bool> visited;
    queue<Node*> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Nó " << curr->val << " vizinhos: ";
        for (Node* neigh : curr->neighbors) {
            cout << neigh->val << " ";
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
        cout << endl;
    }
}

int main() {
    Node* start = createGraph();

    cout << "Percorrendo grafo:\n";
    printGraph(start);
}
