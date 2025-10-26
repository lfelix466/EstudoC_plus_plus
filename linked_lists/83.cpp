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
   ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    imprimeLista(head);

    return head;
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
    ListNode* tail = s.insereList(head, 1);
    tail = s.insereList(tail, 2);
    tail = s.insereList(tail, 3);
    tail = s.insereList(tail, 3); 

    s.deleteDuplicates(head);
}