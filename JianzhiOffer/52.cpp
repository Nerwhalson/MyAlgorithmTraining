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

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        while(ptr1 != ptr2){
            if(ptr1 == nullptr)
                ptr1 = headA;
            else
                ptr1 = ptr1->next;
            if(ptr2 == nullptr)
                ptr2 = headB;
            else   
                ptr2 = ptr2->next;
        }
        return ptr1;
    }
};