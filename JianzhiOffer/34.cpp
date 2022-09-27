#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> buf;
        if(root != nullptr)
            traverse(root, target, 0, ans, buf);
        return ans;
    }

    void traverse(TreeNode* node, int target, int sum, vector<vector<int>>& ans, vector<int> buf){
        sum += node->val;
        if(sum == target && node->left == nullptr && node->right == nullptr){
            buf.push_back(node->val);
            ans.push_back(buf);
        }
        else{
            buf.push_back(node->val);
            if(node->left != nullptr)
                traverse(node->left, target, sum, ans, buf);
            if(node->right != nullptr)
                traverse(node->right, target, sum, ans, buf);
        }
    }
};