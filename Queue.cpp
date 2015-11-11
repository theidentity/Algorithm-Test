#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX=10;

class Queue
{
	int front,rear;
	int limit;
	int *a;
public:

	Queue(int l=MAX)
	{
		limit=l;
		a=new int[limit];
		front=-1;
		rear=-1;
	}

	void enque(int v)
	{
		if(!isFull())
		{
			rear=rear%limit+1;
			a[rear]=v;
		}

	}
	int deque()
	{
		if(!isEmpty())
		{
			int v=a[front];
			front=front%limit+1;
			return v;
		}
	}
	void print()
	{
		if(isEmpty())
			printf("Queue is Empty\n");
		else
		{
			if(front<rear)
				for(int i=(front==-1?0:front);i<=rear;i++)
					cout<<a[i]<<" ";
			else
			{
				for(int i=front;i<limit;i++)
					cout<<a[i]<<" ";
				for(int i=0;i<=rear;i++)
					cout<<a[i]<<" ";
			}
			cout<<endl;	
		}
		
	}

	bool isEmpty()
	{
		return front==rear;
	}

	bool isFull()
	{
		return (rear%limit+1)==front;
	}


};

int main()
{
	Queue Q(4);	Q.print();
	Q.enque(10); Q.print();
	Q.enque(20); Q.print();
	Q.enque(30); Q.print();
	Q.enque(40); Q.print();
	Q.enque(50); Q.print();
	Q.enque(60); Q.print();

	return 0;
}