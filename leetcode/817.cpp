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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, int> buff;
        int len = nums.size(), ans = 0, curr = 0;
        ListNode *pre = head;
        for(int i = 0; i < len; i ++){
            buff[nums[i]] ++;
        }
        while(head != nullptr){
            if(buff[head->val] == 0){
                curr = 0;
            }
            else{
                if(curr == 0)
                    ans ++;
                curr ++;
            }
            head = head->next;
        }
        return ans;
    }
};