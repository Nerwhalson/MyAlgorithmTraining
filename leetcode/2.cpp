#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        ListNode* post;
        int add, overflow = 0;
        while(temp1 != nullptr && temp2 != nullptr)
        {
            add = temp1->val + temp2->val + overflow;
            temp->next = new ListNode(add % 10);
            overflow = add / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
            temp = temp->next;
        }

        if(temp1 != nullptr)
            while(temp1 != nullptr)
            {
                add = temp1->val + overflow;
                temp->next = new ListNode(add % 10);
                overflow = add / 10;
                temp = temp->next;
                temp1 = temp1->next;
            }
        else if(temp2 != nullptr)
            while(temp2 != nullptr)
            {
                add = temp2->val + overflow;
                temp->next = new ListNode(add % 10);
                overflow = add / 10;
                temp = temp->next;
                temp2 = temp2->next;
            }
        
        if(overflow)
            temp->next = new ListNode(1);

        return head->next;
    }
};

void traverse(ListNode *head)
{
    ListNode*temp = head;
    while(temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

ListNode* init(int* list, int n)
{
    ListNode *head = new ListNode(-1);
    ListNode *temp = head;
    for(int i = 0; i < n; i++)
    {
        temp->next = new ListNode(list[i]);
        temp = temp->next;
    }

    return head->next;
}

int main()
{
    int list1[4] = {1, 9, 5, 6};
    int list2[4] = {1};
    ListNode* link1 = init(list1, 4);
    ListNode* link2 = init(list2, 1);
    Solution run;
    ListNode* head = run.addTwoNumbers(link1, link2);
    traverse(head);

    return 0;
}
