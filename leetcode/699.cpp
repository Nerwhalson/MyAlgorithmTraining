// Definition for a binary tree node.
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
    void prune(TreeNode* parent, TreeNode* child, int low, int high, bool root){
        TreeNode* temp;
        if(child == nullptr)
            return;
        if(child->val < low)
        {
            parent->left = child->right;
            prune(parent, child->right, low, high, root);
        }
        else if(child->val > high)
        {
            if(root)
                parent->left = child->left;
            else
                parent->right = child->left;
            prune(parent, child->left, low, high, root);
        }
        else
        {
            prune(child, child->left, low, high, false);
            prune(child, child->right, low, high, false);
        }
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode *src = new TreeNode(-1, root, nullptr);
        prune(src, root, low, high, true);

        return src->left;
    }
};