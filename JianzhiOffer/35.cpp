#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return head;
        Node *temp = head;
        int len, i;
        for(len = 0; temp != nullptr; ++len)
            temp = temp->next;

        unordered_map<Node*, int> origin_map;
        Node **copy_list = new Node*[len];
        Node **origin_list = new Node*[len];

        Node *cur, *random;
        for(i = 0, temp = head; temp != nullptr; ++i)
        {
            cur = new Node(temp->val);
            origin_map[temp] = i;
            origin_list[i] = temp;
            copy_list[i] = cur;
            temp = temp->next; 
        }

        for(i = 1, temp = head; i < len; ++i)
        {
            random = origin_list[i-1]->random;
            copy_list[i-1]->next = copy_list[i];
            if(origin_list[i-1]->random != nullptr)
                copy_list[i-1]->random = copy_list[origin_map[random]];
        }
        random = origin_list[len-1]->random;
        if(origin_list[len-1]->random != nullptr)
            copy_list[len-1]->random = copy_list[origin_map[random]];

        return copy_list[0];
    }
};