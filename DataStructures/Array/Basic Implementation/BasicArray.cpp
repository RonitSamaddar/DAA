#include<iostream>

using namespace std;

#define DEFAULT_CAP 1000

template <typename T>
class Array
{
private:
	T *arr;
	int cap;
	int count;
public:
	Array()
	{
		this->arr=new T(DEFAULT_CAP);
		this->cap=DEFAULT_CAP;
		this->count=0;
	}
	Array(int size)
	{
		this->arr=new T(size);
		this->cap=size;
		this->count=0;
	}

	void printArray()
	{
		if(this->count==0)
		{
			cout<<"ARRAY IS EMPTY!!!"<<endl;
			return;
		}
		
		for(int i=0;i<this->count;i++)
		{
			cout<<this->arr[i]<<" ";
		}
		cout<<endl;
	}
	void insert(T k)
	{
		//Inserts the element k at the end of the array
		//COMPLEXITY = O(1)

		if(this->count==this->cap)
		{
			cout<<"ARRAY FULL!! ELEMENT NOT INSERTED!!"<<endl;
		}
		else
		{
			this->arr[this->count]=k;
			this->count=this->count+1;
		}
	}
	void insert_at(T k,int pos)
	{
		//After insertion the value k will be at pos-th position
		//Complexity = O(N)

		if(this->count==this->cap)
		{
			cout<<"ARRAY FULL!! ELEMENT NOT INSERTED!!"<<endl;
		}
		else if(pos>this->count+1)
		{
			cout<<"INVALID POSITION!! ELEMENT NOT INSERTED!!"<<endl;
		}
		else if(pos==this->count+1)
		{
			this->arr[this->count]=k;
			this->count=this->count+1;
		}
		else
		{

			T temp=this->arr[pos-1];
			this->arr[pos-1]=k;
			for(int i=pos;i<this->count;i++)
			{
				T temp2=this->arr[i];
				this->arr[i]=temp;
				temp=temp2;
			}
			this->arr[this->count]=temp;
			this->count=this->count+1;
		}
	}
	int search(T k)
	{
		//Searches for the index of the given value. If no such value found, returns -1
		//Complexity = O(N)
		int i=0;
		while(i<this->count)
		{
			if(this->arr[i]==k)
			{
				return i;
			}
			else
			{
				i++;
			}
		}
		return -1;
	}

};

int main()
{
	Array<int> *a;
	int c=1;
	int k=0,p=0;
	int ret=1;
	int flag=0;
	cout<<"INTEGER ARRAY"<<endl;
	while(c!=0)
	{

		if(flag==0)
		{
			cout<<"Enter 1 to create array followed by size. (Eg : 1 5)"<<endl;
			cout<<"Enter 0 to exit"<<endl;
			cout<<"ENTER CHOICE"<<endl;
			cin>>c;
			switch(c)
			{
				case 0:
					break;
				case 1:
					cin>>k;
					a=new Array<int>(k);
					flag=1;
					break;
				default:
					cout<<"WRONG CHOICE!!!"<<endl;


			}
		}
		else if(flag==1)
		{
			cout<<"Enter 2 to insert value into the array, followed by the value"<<endl;
			cout<<"Enter 3 to insert value into given position, followed by value and position"<<endl;
			cout<<"Enter 4 to search for index of an element in the array,followed by the element"<<endl;
			cout<<"Enter 5 to find value at a given index, followed by the index"<<endl;
			cout<<"Enter 6 to delete a particular value, followed by the value"<<endl;
			cout<<"Enter 7 to check if array is Empty"<<endl;
			cout<<"Enter 8 to check if array is Full"<<endl;
			cout<<"Enter 9 to get present number of elements in array"<<endl;
			cout<<"Enter 10 to print array"<<endl;
		
			cout<<"Enter 0 to exit"<<endl;
			cout<<"ENTER CHOICE"<<endl;
			cin>>c;
			switch(c)
			{
				case 0:
					break;
				case 2:
					//Inserts at the end
					cin>>k;
					a->insert(k);
					break;
				case 3:
					cin>>k>>p;
					a->insert_at(k,p);
					break;
				case 4:
					cin>>k;
					ret=a->search(k);
					if(ret!=-1)
						cout<<k<<" FOUND AT INDEX "<<ret<<endl;
					else
						cout<<"NO SUCH VALUE FOUND!!!"<<endl;
					break;
				case 10:
					a->printArray();
					break;
			}
		}
	}
	return 1;

}