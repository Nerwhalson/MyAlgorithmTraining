struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        reverse(root);

        return root;
    }

    void reverse(TreeNode* node)
    {
        TreeNode *temp;
        if(node != nullptr)
        {
            temp = node->left;
            node->left = node->right;
            node->right = temp;
            reverse(node->left);
            reverse(node->right);
        }
    }
};