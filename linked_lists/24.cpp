#include <iostream>
using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        ListNode* newHead = head;
        ListNode* prev = nullptr;

        if(head != nullptr){
            if(head->next != nullptr){
                newHead = head->next;
            }
        }

        while(current != nullptr){

            ListNode* first = current;
            if(current->next != nullptr){ 
                ListNode* second = current->next;
                current = current->next->next;

                first->next = first->next->next;
                second->next = first;

                if(prev != nullptr){
                    prev->next = second;
                }
            }else{
                current = current->next;
            }
            prev = first;
        }

        imprimeLista(newHead);
        return newHead;
    }

public: 
    ListNode* insereList(ListNode* tail, int num){
        ListNode* newitem = new ListNode(num);

        if(tail != nullptr){
            tail->next = newitem;
        }

        return newitem;
    }

public: 
void imprimeLista(ListNode* head){
    if (head == nullptr) return;
    cout << head->val << " ";
    imprimeLista(head->next);
}

};

int main(){
    Solution s;
    ListNode* head = s.insereList(nullptr, 1);
    ListNode* tail = s.insereList(head, 2);
    tail = s.insereList(tail, 3);
    tail = s.insereList(tail, 4); 

    s.swapPairs(head);
}