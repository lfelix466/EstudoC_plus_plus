#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* node;
};

Node* inserirNo(int valor, Node*& no){
    Node* novo = new Node();
    novo->data = valor;
    novo->node = nullptr;
    no->node = novo;
    return novo;
}

void imprimirLista(Node* no){
    do{
        cout << no->data << " ";
        no = no->node;
    }while(no != nullptr);
}

void apagarLista(Node* no){
    Node* aux = nullptr;
    
    do{
        aux = no->node;
        cout << "Apagando: " << no->data;
        delete no;
        no = aux;
    }while(no != nullptr);
}

int main(){

    Node* lista = new Node();
    Node* ultimo = nullptr;

    lista->data = 10;
    lista->node = nullptr;   

    ultimo = inserirNo(20, lista);
    ultimo = inserirNo(30, ultimo);
    ultimo = inserirNo(40, ultimo);
    ultimo = inserirNo(50, ultimo);
    ultimo = inserirNo(60, ultimo);
    //imprimirLista(lista);
    apagarLista(lista);

    return 0;
}