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
		else if(start==NULL)
		{
			//but pos > 1
			cout<<"INVALID POSITION!! NO INSERTION DONE."<<endl;
		}
		else		
		{
			//General case (atleast one node and pos>1)
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
			if(p==NULL)
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
	T retrieve(int pos)
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
	LinkedList<int> *L;
	int c=1;
	int k=0,p=0;
	int ret=1;
	Node<int> *nret=NULL;
	int flag=0;
	cout<<"INTEGER LIST"<<endl;
	while(c!=0)
	{

		if(flag==0)
		{
			cout<<"Enter 1 to create list"<<endl;
			cout<<"Enter 0 to exit"<<endl;
			cout<<"ENTER CHOICE"<<endl;
			cin>>c;
			switch(c)
			{
				case 0:
					break;
				case 1:
					L=new LinkedList<int>();
					flag=1;
					break;
				default:
					cout<<"WRONG CHOICE!!!"<<endl;


			}
		}
		else if(flag==1)
		{
			cout<<"\nEnter 1 to insert value at start, followed by the value"<<endl;
			cout<<"Enter 2 to insert value at end, followed by the value"<<endl;
			cout<<"Enter 3 to insert value into given position, followed by value and position"<<endl;
			cout<<"Enter 4 to search for pointer to node containing a value,followed by the value"<<endl;
			cout<<"Enter 5 to find value at a given position, followed by the position"<<endl;
			cout<<"Enter 6 to delete start node"<<endl;
			cout<<"Enter 7 to delete end node"<<endl;
			cout<<"Enter 8 to delete node at a given position,followed by position"<<endl;
			cout<<"Enter 9 to check if array is Empty"<<endl;
			cout<<"Enter 10 to get present number of elements in array"<<endl;
			cout<<"Enter 11 to print array"<<endl;
		
			cout<<"Enter 0 to exit"<<endl;
			cout<<"ENTER CHOICE"<<endl;
			cin>>c;
			switch(c)
			{
				case 0:
					break;
				case 1:
					cin>>k;
					L->insert_start(k);
					break;
				case 2:
					cin>>k;
					L->insert_end(k);
					break;
				case 3:
					cin>>k>>p;
					L->insert_pos(k,p);
					break;
				case 4:
					cin>>k;
					nret=L->search(k);
					if(nret!=NULL)
						cout<<k<<" FOUND AT POINTER "<<nret<<endl;
					else
						cout<<"NO SUCH VALUE FOUND!!!"<<endl;
					break;
				case 5:
					cin>>p;
					ret=L->retrieve(p);
					if(ret!='\0')
					{
						cout<<"ELEMENT AT POSITION p = "<<ret<<endl;
					}
					break;
				case 6:
					L->delete_start();
					break;
				case 7:
					L->delete_end();
					break;
				case 8:
					cin>>p;
					L->delete_pos(p);
					break;
				case 9:
					ret=L->isEmpty();
					if(ret)
						cout<<"EMPTY!!"<<endl;
					else
						cout<<"NOT EMPTY!!"<<endl;
					break;
				case 10:
					ret=L->size();
					cout<<"NUMBER OF ELEMENTS IN LIST = "<<ret<<endl;
					break;
				case 11:
					L->print_list();
					break;
				default:
					cout<<"INVALID CHOICE !!!"<<endl;
					break;
			}
		}
	}
	return 1;

}