#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        stack<TreeNode*> visit, buf;
        vector<vector<int>> ans;
        if(root != nullptr)
            buf.push(root);
        while(!buf.empty())
        {
            vector<int> temp;
            while(!buf.empty())
            {
                visit.push(buf.top());
                buf.pop();
            }
            while(!visit.empty())
            {
                temp.push_back(visit.top()->val);
                if(visit.top()->left != nullptr)
                    buf.push(visit.top()->left);
                if(visit.top()->right != nullptr)
                    buf.push(visit.top()->right);
                visit.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};