#include <iostream>

class MyLinkedList {
public:
    MyLinkedList() {
        this->val = 0;
        this->len = 0;
        this->next = nullptr;
    }
    
    int get(int index) {
        if(index > -1 && index < this->len){
            MyLinkedList* temp = this->next;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        MyLinkedList *add = new MyLinkedList;
        add->val = val;
        add->next = this->next;
        this->next = add;
        this->len++;
    }
    
    void addAtTail(int val) {
        MyLinkedList *temp = new MyLinkedList;
        MyLinkedList *tail = this;
        temp->val = val;
        while(tail->next != nullptr)
            tail = tail->next;
        tail->next = temp;
        this->len++;
    }
    
    void addAtIndex(int index, int val) {
        if(this->len >= index && index > -1){
            MyLinkedList *ptr = this;
            for(int i = 0; i < index; i++)
                ptr = ptr->next;
            MyLinkedList *temp = new MyLinkedList;
            temp->val = val;
            temp->next = ptr->next;
            ptr->next = temp;
            this->len++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(this->len > index && index > -1){
            MyLinkedList *ptr = this;
            for(int i = 0; i < index; i++)
                ptr = ptr->next;
            ptr->next = ptr->next->next;
            this->len--;
        }
    }

    void traverse(){
        MyLinkedList *temp = this->next;
        while(temp != nullptr){
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

private:
    int val;
    int len;
    MyLinkedList* next;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

 int main(){
    MyLinkedList *head = new MyLinkedList;
    head->addAtHead(1);
    head->addAtHead(2);
    head->addAtHead(3);
    head->traverse();
    head->addAtIndex(2, 5);
    head->traverse();
    head->deleteAtIndex(1);
    head->traverse();

    return 0;
 }