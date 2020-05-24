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
		//Time Complexity = O(1)
		//Space Complexity = O(1)
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
		//Time Complexity = O(n)
		//Space Complexity = O(1)

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
		//Time Complexity = O(n)
		//Space Complexity = O(1)

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
	void delete_start()
	{
		//Deletes the node at the beginning of the list
		//Time Complexity = O(1)
		//Space Complexity = O(1)

		if(this->start==NULL)
		{
			//Empty List Case
			cout<<"List is Empty!!!"<<endl;
		}
		else
		{
			//Storing the first node and taking start pointer to the second node
			Node<T> *temp=this->start;
			this->start=this->start->get_next();

			//Isolating the first node and freeing its allocated memory
			temp->set_next(NULL);
			delete(temp);
		}
	}
	void delete_end()
	{
		//Deletes the node at the end of the list
		//Time Complexity = O(n)
		//Space Complexity = O(1)

		if(this->start==NULL)
		{
			//Empty List Case
			cout<<"List is Empty!!!"<<endl;
		}
		else if(this->start->get_next()==NULL)
		{
			//Only one element
			//This will be same as deleting the first element
			this->delete_start();

		}
		else
		{
			//Traversing to the node before the end node
			Node<T> *temp=this->start;
			while((temp->get_next())->get_next()!=NULL)
			{
				temp=temp->get_next();
			}
			//Loop will stop with temp being the penultimate node
			Node<T> *p=temp->get_next();
			temp->set_next(NULL);
			delete(p);
		}

	}
	void delete_pos(int pos)
	{
		//Deletes the node at the position pos
		//Time Complexity = O(n)
		//Space Complexity = O(1)

		if(this->start==NULL)
		{
			//Empty List Case
			cout<<"List is Empty!!!"<<endl;
		}
		else if(this->start->get_next()==NULL)
		{
			//Single element list case
			if(pos==1)
			{
				//Same as delete beginning
				this->delete_start();
			}
			else
			{
				cout<<"INVALID POSITION!! NO DELETION DONE."<<endl;
			}
		}
		else
		{
			if(pos==1)
			{
				//Same as delete beginning
				this->delete_start();
			}
			else
			{
				//General case (List contains more than one node and pos >1)
				int index=1;							//Current node number
				Node<T> *p=this->start;
				while(1)
				{
					if((p->get_next()==NULL)||(index==pos-1))		//We must stop at (pos-1)-th node
					{
						break;
					}
					p=p->get_next();
					index++;
				}
				if(p->get_next()==NULL && index<pos-1)
				{
					//If we pos>(number of elements), then pos is invalid
					cout<<"INVALID POSITION!! NO DELETION DONE."<<endl;
				}
				else
				{
					//We have stopped at the previous node
					Node<T> *temp=p->get_next();
					p->set_next(temp->get_next());
					delete(temp);
				}
			}
		}
		
	}
	Node<T> *search(int val)
	{
		Node<T> *temp=this->start;
		while(temp!=NULL)
		{
			if(temp->get_data()==val)
			{
				return temp;
			}
			temp=temp->get_next();
		}
		return NULL;
	}
	T retreive(int pos)
	{
		Node<T> *temp=this->start;
		int index=1;
		while(temp!=NULL)
		{
			if(index==pos)
			{
				return temp->get_data();
			}
			index++;
			temp=temp->get_next();
		}
		return '\0';
	}

	int isEmpty()
	{
		return(this->start==NULL);
	}
	int size()
	{
		Node<T> *temp=this->start;
		int sz=0;
		while(temp!=NULL)
		{
			sz++;
			temp=temp->get_next();
		}
		return sz;
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
	Node<int> *res=L->search(4);
	if(res==NULL)
	{
		cout<<"NOT FOUND!!"<<endl;
	}
	else
	{
		cout<<"FOUND !! NODE POINTER = "<<res<<endl;
	}
	cout<<"Value at position 4 = "<<L->retreive(4)<<endl;
	cout<<"List isEmpty = "<<L->isEmpty()<<endl;
	cout<<"Number of elements = "<<L->size()<<endl;
	L->print_list();

	L->delete_start();
	L->delete_end();
	L->delete_pos(3);
	L->print_list();

}
