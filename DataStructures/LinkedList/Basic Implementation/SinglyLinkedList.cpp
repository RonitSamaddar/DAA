#include<iostream>

using namespace std;

template <typename T>
class Node
{
private:
	T val;
	Node *next;
public:
	Node()
	{
		this->next=NULL;
	}
	Node(T v)
	{
		this->val=v;
		this->next=NULL;
	}
	void set_data(T v)
	{
		this->val=v;
	}
	T get_data()
	{
		return this->val;
	}
	void set_next(Node *p)
	{
		this->next=p;
	}
	Node *get_next()
	{
		return this->next;
	}

};
template <typename T>
class LinkedList
{
private:
	Node<T> *start;
public:
	LinkedList()
	{
		start=NULL;
	}
	void insert_start(T val)
	{
		Node<T> *temp=new Node<T>(val);
		if(this->start==NULL)
		{
			//Empty List Case
			this->start=temp;
		}
		else
		{
			//General case
			temp->set_next(this->start);
			this->start=temp;
		}
	}
	void print_list()
	{
		Node<T> *temp=start;
		while(temp!=NULL)
		{
			cout<<temp->get_data()<<" ";
			temp=temp->get_next();
		}
		cout<<endl;

	}

};
int main()
{
	LinkedList<int> *L=new LinkedList<int>();
	L->insert_start(1);
	L->insert_start(2);
	L->print_list();
}
