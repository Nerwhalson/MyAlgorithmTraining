class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        head = new node;
        empty = true;
    }
    
    void push(int x) {
        node* temp = new node;
        temp->val = x;
        if(empty)
        {
            temp->min_value = x; 
            empty = false;
        }
        else
            temp->min_value = x < head->min_value ? x : head->min_value;
        temp->next = head;
        head = temp;
    }
    
    void pop() {
        head = head->next;
        if(head->next == nullptr)
            empty = true;
    }
    
    int top() {
        return head->val;
    }
    
    int min() {
        return head->min_value;
    }

    typedef struct node
    {
        int val;
        int min_value;
        node* next;
        node() : val(0), min_value(0), next(nullptr) {}
    }node;

    bool empty;
    node* head;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */