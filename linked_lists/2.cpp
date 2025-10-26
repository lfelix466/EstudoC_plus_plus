#include <iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = nullptr;
        ListNode* l4 = nullptr;
        int soma, resto = 0, carry = 0;
        
        soma = l1->val + l2->val;
        if(temCarry(soma)){
            resto = soma%10;
            carry = 1;
            l3 = new ListNode(resto);
        }else{
            l3 = new ListNode(soma);
        }

        proximoPasso(l1, l2);

        while(l1 != nullptr || l2 != nullptr){

            if(l1 == nullptr){
                soma = l2->val + carry;
            }else if(l2 == nullptr){
                soma = l1->val + carry;
            }else{
                soma = l1->val + l2->val + carry;
            }

            if(temCarry(soma)){
                resto = soma%10;
                carry = 1;
                l3 = new ListNode(resto, l3);
            }else{
                carry = 0;
                l3 = new ListNode(soma, l3);
            }
            
            proximoPasso(l1, l2);
        }
        
        if(carry == 1){
            l3 = new ListNode(1, l3);
        }
        
        imprimeLista(l3);
        cout << "\n";
        imprimeListaReal(l3);

        cout << "\n\n";
        imprimeLista(l4);
        cout << "\n";
        imprimeListaReal(l4);

        return reverseList(l3);
    }
    
public: 
    bool temCarry(int soma){

        if(soma>9){
            return true;
        }
        return false;
    }

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

public: 
    void proximoPasso(ListNode*& l1, ListNode*& l2){
        if(l1 != nullptr){
            l1 = l1->next;
        }

        if(l2 != nullptr){
            l2 = l2->next;
        }
    }

public: 
    int contTamanho(ListNode* li, int soma){

        if(li->next != nullptr){
            soma = contTamanho(li->next, soma);
        }
        soma++;
        return soma;
    }

public: 
    void imprimeLista(ListNode* no){
        do{
            cout << no->val << " ";
            no = no->next;
        }while(no != nullptr);
    }

public:
    void imprimeListaReal(ListNode* no){
        if(no->next != nullptr){
            imprimeListaReal(no->next);
        }
        cout << no->val << " ";
    }
};

int main(){
    Solution s;
    //ListNode* l1 = nullptr;
    //ListNode* l2 = nullptr;

    // ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(9)));
    // ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9))));

    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    s.addTwoNumbers(l1, l2);
    //s.imprimeLista(no);

    return 0;
}