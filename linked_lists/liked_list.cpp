#include <iostream>

struct Node {
    int data;
    Node* next;
};

void inserirNoInicio(Node*& head, int valor) {
    Node* novo = new Node;
    novo->data = valor;
    novo->next = head;
    head = novo;
}

void removerDoInicio(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void imprimirLista(Node* head) {
    Node* atual = head;
    while (atual != nullptr) {
        std::cout << atual->data << " -> ";
        atual = atual->next;
    }
    std::cout << "NULL\n";
}

int main() {
    Node* lista = nullptr;

    inserirNoInicio(lista, 30);
    inserirNoInicio(lista, 20);
    inserirNoInicio(lista, 10);

    std::cout << "Lista atual:\n";
    imprimirLista(lista);

    std::cout << "Removendo o primeiro elemento...\n";
    removerDoInicio(lista);

    std::cout << "Lista após remoção:\n";
    imprimirLista(lista);

    return 0;
}
