#include<iostream>

using namespace std;

template <typename T>
class Node
{
private:
	T val;
	Node *prev;
	Node *next;
public:
	Node()
	{
		this->prev=NULL;
		this->next=NULL;
	}
	Node(T v)
	{
		this->val=v;
		this->prev=NULL;
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
	void set_prev(Node *p)
	{
		this->prev=p;
	}
	Node *get_prev()
	{
		return this->prev;
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

	}
	void insert_end(T val)
	{

	}
	void insert_pos(T val,int pos)
	{

	}
	void delete_start()
	{

	}
	void delete_end()
	{

	}
	void delete_pos(int pos)
	{

	}
	Node<T> *search(T val)
	{

	}
	T retrieve(int pos)
	{

	}
	int isEmpty()
	{

	}
	int size()
	{

	}
	void print_list()
	{
		
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
					else
					{
						cout<<"INVALID POSITION"<<endl;
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