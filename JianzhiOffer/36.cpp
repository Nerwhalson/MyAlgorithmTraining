class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* pre = nullptr, *head;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        dfs(root);
        pre->right = head;
        head->left = pre;
        return head;
    }

    void dfs(Node* node){
        if(node == nullptr)
            return;
        dfs(node->left);
        if(pre != nullptr)
            pre->right = node;
        else
            head = node;
        node->left = pre;
        pre = node;
        dfs(node->right);
    }
};