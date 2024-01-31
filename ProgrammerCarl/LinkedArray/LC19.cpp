#include <cstddef>
#include <iostream>
#include <limits>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = head;
        int count = 0;
        for(int i = 0; i < n; i ++)
            right = right->next;
        if(right == nullptr)
            return head->next;
        while(right->next != nullptr){
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return head;
    }
};

int main(){
    Solution run;
    struct ListNode *head = new struct ListNode(1);
    struct ListNode *temp = head;
    for(int i = 1; i < 7; i++){
        temp->next = new struct ListNode(i+1);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = run.removeNthFromEnd(head, 1);
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
