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
        return head;
    }
};

int main(){
    Solution run;
    struct ListNode *head = new struct ListNode(1);
    struct ListNode *temp = head;
    for(int i = 1; i < 5; i++){
        temp->next = new struct ListNode(i+1);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = run.reverseList(head);
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}