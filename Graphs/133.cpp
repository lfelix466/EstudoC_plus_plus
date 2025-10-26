#include <vector>
#include <unordered_map>
using namespace std;

// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // Grafo vazio

        unordered_map<Node*, Node*> visited; // original -> clone
        return dfs(node, visited);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        // Se já foi clonado, retorna o clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Cria o clone do nó atual
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Clona todos os vizinhos recursivamente
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }

        return clone;
    }
};
