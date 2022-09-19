#include <stack>
#include <iostream>

using namespace std;

class CQueue {
public:
    CQueue() {
        s1 = new stack<int>;
        s2 = new stack<int>;
    }
    
    void appendTail(int value) {
        s1->push(value);
    }
    
    int deleteHead() {
        if(s1->empty())
            return -1;

        int tail;
        while(!s1->empty())
        {
            s2->push(s1->top());
            s1->pop();
        }
        tail = s2->top();
        s2->pop();
        while(!s2->empty())
        {
            s1->push(s2->top());
            s2->pop();
        }

        return tail;
    }

    stack<int> *s1, *s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    CQueue run;
    

    return 0;
}
