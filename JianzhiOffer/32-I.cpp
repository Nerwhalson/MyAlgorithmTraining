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
 
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        stack<TreeNode*> visit, buf;
        vector<int> ans;
        if(root != nullptr)
            buf.push(root);
        while(!buf.empty())
        {
            while(!buf.empty())
            {
                visit.push(buf.top());
                buf.pop();
            }
            while(!visit.empty())
            {
                ans.push_back(visit.top()->val);
                if(visit.top()->left != nullptr)
                    buf.push(visit.top()->left);
                if(visit.top()->right != nullptr)
                    buf.push(visit.top()->right);
                visit.pop();
            }
        }
        return ans;
    }
};