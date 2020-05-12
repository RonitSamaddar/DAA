#include<iostream>

using namespace std;

template <typename T>
class Array
{
private:
	T *arr;
	int cap;
	int count;

};

int main()
{
	Array<int> *a;
	int c=1;
	int k=0;
	cout<<"INTEGER ARRAY"<<endl;
	while(c!=0)
	{
		cout<<"Enter 1 to create array followed by size. (Eg : 1 5)"<<endl;
		cout<<"Enter 2 to insert value into the array, followed by the value"<<endl;
		cout<<"Enter 3 to insert value into given position, followed by value and position"<<endl;
		cout<<"Enter 4 to search for an element in the array,followed by the element"<<endl;
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
		}
	}
	return 1;

}