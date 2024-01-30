struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val)
            head = head->next;
        ListNode* ptr = head;
        while(ptr != nullptr && ptr->next != nullptr){
            while(ptr->next != nullptr && ptr->next->val == val)
                ptr->next = ptr->next->next;
            ptr = ptr->next;
        }
        return head;
    }
};