struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        post_traverse(root, k);
        return ans;
    }
    int ans;
    void post_traverse(TreeNode* node, int& k){
        if(node == nullptr)
            return;
        post_traverse(node->right, k);
        k -= 1;
        if(k == 0)
            ans = node->val;
        post_traverse(node->left, k);
    }
};