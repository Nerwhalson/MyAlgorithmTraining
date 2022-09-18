struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *lptr, *rptr;
        if(root != nullptr)
            return judge(root->left, root->right);
        else
            return true;
    }

    bool judge(TreeNode* lptr, TreeNode* rptr)
    {
        if(lptr != nullptr && rptr != nullptr)
        {
            if(lptr->val == rptr->val)
                return judge(lptr->left, rptr->right) & judge(lptr->right, rptr->left);
            else
                return false;
        }
        else if(lptr == nullptr && rptr == nullptr)
            return true;
        else
            return false;
    }
};