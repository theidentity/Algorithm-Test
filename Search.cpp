#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class Search
{
	int *a;
	int size;
public:
	Search(int l)
	{
		size=l;
		a=new int [size+1];
	}

	int getElementAt(int i)
	{
		if(i>=size)
			return -1;
		return a[i];
	}

	void populateArray()
	{
		for(int i=0;i<size;i++)
			a[i]=rand()%10+1;
	}

	void populateArrayinOrder()
	{
		for(int i=0;i<size;i++)
			a[i]=i*10+1;
	}


	void printArray()
	{
		for(int i=0;i<size;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}

	int LinearSearch(int key)
	{
		for(int i=0;i<size;i++)
			if(a[i]==key)
				return i;
		return -1;
	}

	int BinarySearch(int key)
	{
		int low,mid,high;
		low=0;high=size-1;
		while(low<high)
		{
			mid=(low+high)/2;
			if(a[mid]==key)
				return mid;
			else if(key>a[mid])
				low=mid+1;
			else
				high=mid;
		}
		return -1;
	}

	int LinearSearchOptimal(int find) 
	{
		/* Note : The above solution will only work
		if there is some empty slots availablein the array . If that isn't the case,
		then adding elements at the end of array can lead to program crash !!!
		The above note can be easily applied for linked lists , where we can simply
		insert a node at the end of the linked list and perform the linear scan.*/
		int i=0;
		a[size]=find;
		while(a[i]!=find)
			i++;
		if(i==size)
			return -1;
		else
			return i;
	}

	int BinarySearchOptimal(int find)
	{
		int low,mid,high;
		low=0;high=size-1;
		while(low<high)
		{
			mid=(low+high)/2;
			if(find>a[mid])
				low=mid+1;
			else
				high=mid-1;
		}

		if(a[mid]==find)
			return mid;
		else
			return -1;
	}
};

int main()
{
	Search s1(10);
	s1.populateArrayinOrder();
	s1.printArray();
	int find=s1.getElementAt(2);
	// cout<<find<<" is at "<<s1.LinearSearch(find)<<endl;
	// cout<<find<<" is at "<<s1.BinarySearch(find)<<endl;
	// cout<<find+5<<" is at "<<s1.LinearSearch(find+5)<<endl;
	// cout<<find+5<<" is at "<<s1.BinarySearch(find+5)<<endl;
	cout<<find<<" is at "<<s1.LinearSearchOptimal(find)<<endl;
	cout<<find+5<<" is at "<<s1.LinearSearchOptimal(find+5)<<endl;
	cout<<find<<" is at "<<s1.BinarySearchOptimal(find)<<endl;
	cout<<find+5<<" is at "<<s1.BinarySearchOptimal(find+5)<<endl;
	return 0;
}
