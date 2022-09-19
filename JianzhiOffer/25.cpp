#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        ListNode *ptr1, *ptr2, *temp;
        if(l1->val > l2->val){
            temp = l2;
            ptr1 = l1;
            ptr2 = l2->next;
        }
        else{
            temp = l1;
            ptr1 = l1->next;
            ptr2 = l2;
        }
        while(ptr1 != nullptr && ptr2 != nullptr){
            if(ptr1->val > ptr2->val){
                temp->next = ptr2;
                temp = temp->next;
                ptr2 = ptr2->next;
            }
            else{
                temp->next = ptr1;
                temp = temp->next;
                ptr1 = ptr1->next;
            }
        }
        if(ptr1 != nullptr)
            temp->next = ptr1;
        else
            temp->next = ptr2;

        return l1->val > l2->val ? l2 : l1;
    }
};