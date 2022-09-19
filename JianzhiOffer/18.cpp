struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        else if(head->val == val)
            return head->next;
        ListNode* temp = head;
        while(temp->next != nullptr)
        {
            if(temp->next->val == val)
            {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }

        return head;
    }
};