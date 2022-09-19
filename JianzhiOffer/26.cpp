struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr && B == nullptr)
            return true;
        else if(A == nullptr)
            return false;
        else if(B == nullptr)
            return false;
        return (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool recur(TreeNode* Anode, TreeNode* Bnode){
        if(Bnode == nullptr)
            return true;
        else if(Anode == nullptr || Anode->val != Bnode->val)
            return false;
        else
            return recur(Anode->left, Bnode->left) && recur(Anode->right, Bnode->right);
    }
};