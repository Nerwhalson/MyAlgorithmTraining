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
    ListNode* swapPairs(ListNode* head) {
        if(head != nullptr && head->next != nullptr){
            ListNode* left = head;
            ListNode* pre = head;
            ListNode* right = head->next;
            left->next = right->next;
            right->next = left;
            head = right;
            while(left->next != nullptr){
                pre = left;
                left = left->next;
                right = left->next;
                if(right != nullptr){
                    left->next = right->next;
                    right->next = left;
                    pre->next = right;
                }
            }
        }
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
    temp = run.swapPairs(head);
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}