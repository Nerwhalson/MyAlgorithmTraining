#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <istream>

using namespace std;

template <typename T>
struct Node
{
	T x;
	int time;
	Node<T>* next;
	Node<T>* pre;
};

template <typename T>
struct Node_list
{
	Node<T>* head;
	Node<T>* end;

	//初始化链表
	void init()
	{
		this->head = new Node<T>;
		this->end = new Node<T>;
		this->head->next = this->end;
		this->end->next = NULL;
	};

	//尾插法添加节点
	void append_end(T n)
	{
		Node<T>* nlist = new Node<T>;
		this->end->x = n;
		this->end->next = nlist;
		this->end = this->end->next;
		this->end->next = NULL;
	};

	//头插法添加节点
	void append_head(T n)
	{
		Node<T>* nlist = new Node<T>;
		nlist->x = n;
		nlist->next = this->head->next;
		this->head->next = nlist;
	};

	//查找节点
	Node<T>* find_ele(T n)
	{
		Node<T>* temp = new Node<T>;
		temp = this->head->next;
		while (temp != this->end)
		{
			if (temp->x == n) 
			{
				return temp;
			}
			temp = temp->next;
		}
		cout << "fail to find " << n << "\n";
		return NULL;
	};

	//销毁链表
	void destory()
	{
		Node<T>* temp1 = this->head;
		Node<T>* temp2 = this->head->next;
		while (temp2 != NULL)
		{
			delete[] temp1;
			temp1 = temp2;
			temp2 = temp2->next;
		}
		delete[] temp1;
	}

	//按位插入节点
	void insert_pos(Node<T>* node, int pos)
	{
		Node<T>* temp = head;
		for (int i = 0; i < pos; i++)
		{
			temp = temp->next;
			if (temp == this->end)
			{
				cout << "out of range\n";
				return;
			}
		}
		node->next = temp->next;
		temp->next = node;
	}

	//按值插入节点(插入该值所在节点后）
	//PS: 当仅有首尾节点时会出bug，等有需求的时候再改
	void insert_ele(Node<T>* node, T n)
	{
		Node<T>* temp = head;
		while (temp->x != n)
		{
			temp = temp->next;
			if (temp == this->end)
			{
				cout << "fail to fing" << n << "\n";
				return;
			}
		}
		node->next = temp->next;
		temp->next = node;
	}

	//按位删除节点
	void insert_pos(int pos)
	{
		Node<T>* temp = head;
		for (int i = 1; i < pos; i++)
		{
			temp = temp->next;
			if (temp == this->end)
			{
				cout << "fail to delete NO." << n << " Node";
				return;
			}
		}
		temp->next = temp->next->next;
	}

	//按值删除节点
	void insert_ele(T n)
	{
		Node<T>* pre = head;
		Node<T>* temp = head->next;
		while (temp->next != NULL)
		{
			if (temp->x == n)
			{
				pre->next = temp->next;
				return;
			}
			pre = temp;
			temp = temp->next;
		}
		cout << "fail to delete " << n;
	}

	//遍历节点
	void traverse()
	{
		Node<T>* temp = new Node<T>;
		temp = this->head->next;
		while (temp != this->end)
		{
			cout << temp->x << " ";
			temp = temp->next;
		}
	};
};
	       

int main()
{
	Node_list<string> nlist;
	Node<string> *node = new Node<string>;
	int num;
	string temp;
	nlist.init();

	nlist.destory();
	return 0;
}