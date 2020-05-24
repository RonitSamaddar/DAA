#include<iostream>

using namespace std;

template <typename T>
class Node
{
private:
	T val;
	Node *next;
public:
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
int main()
{
	Node<int> *N=new Node<int>(5);
	Node<int> *M=new Node<int>(1);
	N->set_next(M);
	cout<<N->get_data()<<endl;
	cout<<N->get_next()<<endl;
}
