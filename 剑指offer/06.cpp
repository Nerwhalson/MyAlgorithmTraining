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
    vector<int> reversePrint(ListNode* head) {
        int* list;
        int len = 0;
        ListNode *temp = head;
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        temp = head;
        list = new int[len];
        for(int i = 0; i < len; i++)
        {
            list[len-i-1] = temp->val;
            temp = temp->next;
        }
        vector<int> vec(list, list + len);

        return vec;
    }
};