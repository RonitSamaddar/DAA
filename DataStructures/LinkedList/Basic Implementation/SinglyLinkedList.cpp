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
		//Inserts node with value val at the beginning of the list
		//Complexity = O(1)
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
	void insert_end(T val)
	{
		//Inserts node with value val at the end of the list
		//Complexity = O(n)

		Node<T> *temp=new Node<T>(val);
		if(this->start==NULL)
		{
			//Empty List Case
			this->start=temp;
		}
		else
		{
			//General case
			Node<int> *p=this->start;
			while(p->get_next()!=NULL)
			{
				p=p->get_next();
			}
			p->set_next(temp);
		}
	}
	void insert_pos(T val,int pos)
	{
		//Inserts node with value val at the position pos
		//Complexity = O(n)

		if(pos==1)
		{
			//Insert at beginning case
			this->insert_start(val);
		}
		else
		{
			//General case
			int index=1;							//Current node number
			Node<T> *temp=new Node<T>(val);
			Node<T> *p=this->start;
			while(1)
			{
				if((p==NULL)||(index==pos-1))		//We must stop at (pos-1)-th node
				{
					break;
				}
				p=p->get_next();
				index++;
			}
			if(p==NULL && index<pos-1)
			{
				//If we pos>(number of elements+1), then pos is invalid
				cout<<"INVALID POSITION!! NO INSERTION DONE."<<endl;
			}
			else
			{
				//We have stopped at the previous node
				temp->set_next(p->get_next());
				p->set_next(temp);
			}
		}
	}
	void print_list()
	{
		//Prints each node as we traverse the entire list
		//Complexity = O(n)

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
	L->insert_end(1);
	L->insert_start(2);
	L->insert_end(3);
	L->insert_pos(4,2);
	L->insert_pos(5,4);
	L->insert_pos(6,6);
	L->print_list();
}
