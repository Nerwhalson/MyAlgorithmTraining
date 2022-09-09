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
    ListNode* reverseList(ListNode* head) {
        ListNode *middle, *end, *temp;
        if(head == NULL)
            return head;
        middle = head->next;
        head->next = NULL;
        if(middle == NULL)
            return head;
        end = middle->next;
        while(end != NULL)
        {
            middle->next = head;
            head = middle;
            middle = end;
            end = end->next;
        };
        middle->next = head;

        return middle;
    }
};