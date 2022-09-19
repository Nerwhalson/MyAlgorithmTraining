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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        queue<ListNode*> q;
        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(count < k)
                q.push(temp);
            else{
                q.pop();
                q.push(temp);
            }
            count++;
            temp = temp->next;
        }

        return q.front();
    }
};