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
    ListNode* reverseList(ListNode* head) {
        ListNode *left = head;
        ListNode *mid = head;
        ListNode *right = head;
        if(head != nullptr && head->next != nullptr){
            mid = head->next;
            right = mid->next;
            left->next = nullptr;
            while(right != nullptr){
                mid->next = left;
                left = mid;
                mid = right;
                right = right->next;
            }
            mid->next = left;
            head = mid;
        }
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
