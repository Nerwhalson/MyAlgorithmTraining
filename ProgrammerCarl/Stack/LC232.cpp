#include <stack>
#include <iostream>

class MyQueue {
public:
    MyQueue() {
        this->isEmpty = true;
        this->top_ele = 0;
        this->container1 = new std::stack<int>;
        this->container2 = new std::stack<int>;
    }
    
    void push(int x) {
        if(isEmpty){
            this->top_ele = x;
            this->isEmpty = false;
        }
        this->container1->push(x);
    }
    
    int pop() {
        int temp_top = this->top_ele;
        while(!this->container1->empty()){
            this->container2->push(this->container1->top());
            this->container1->pop();
        }
        this->container2->pop();
        if(this->container2->empty()){
            this->isEmpty = true;
        }
        else{
            this->top_ele = this->container2->top();
            while(!this->container2->empty()){
                this->container1->push(this->container2->top());
                this->container2->pop();
            }
        }
        return temp_top;
    }
    
    int peek() {
        return this->top_ele;
    }
    
    bool empty() {
        return isEmpty;
    }

    ~MyQueue(){
        delete this->container1;
        delete this->container2;
    }

private:
    int top_ele;
    bool isEmpty;
    std::stack<int>* container1;
    std::stack<int>* container2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    MyQueue queue;
    queue.push(1);
    std::cout << queue.peek() << std::endl;
    queue.push(2);
    std::cout << queue.peek() << std::endl;
    queue.pop();
    std::cout << queue.peek() << std::endl;
    std::cout << queue.empty() << std::endl;

    return 0;
}
