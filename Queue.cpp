#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Queue
{
	int *a;
	int front, rear;
	int max;

public:
	Queue(int l = 4)
	{
		max = l;
		a = new int[l];
		front = -1;
		rear = -1;
	}

	void enqueue(int v)
	{
		if (!isFull())
		{
			if (front == -1)
				front = 0;
			rear = (rear + 1) % max;
			a[rear] = v;
		}
		else
		{
			printf("Queue is Full\n");
		}
	}

	int dequeue()
	{
		if (front == rear && front != -1)
		{
			int v = a[front];
			front = -1;
			rear = -1;
			return v;
		}
		if (!isEmpty())
		{

			int v = a[front];
			front = (front + 1) % max;
			return v;
		}
		else
			printf("Queue is Empty\n");

		return -1;
	}
	bool isEmpty()
	{
		return (front == -1 && rear == -1);
	}

	bool isFull()
	{
		return (abs(front - rear) == max-1);
	}

	int getSize()
	{
		if(isEmpty())
			return 0;
		else
			return(abs(front - rear)+1);
	}


	void printQueue()
	{
		// cout << front << " " << rear << endl;
		if (front == -1 && rear == -1)
			printf("Queue is Empty\n");
		else if (front <= rear)
		{
			for (int i = front; i <= rear; i++)
				cout << a[i] << " ";
			cout << endl;
		}
		else
		{
			for (int i = front; i <= max; i++)
				cout << a[i] << " ";
			for (int i = 0; i <= rear; i++)
				cout << a[i] << " ";
			cout << endl;
		}
	}

};

int main()
{
	Queue q1(4);	q1.printQueue();
	q1.enqueue(10);	q1.printQueue();		
	q1.enqueue(20);	q1.printQueue();		
	q1.enqueue(30);	q1.printQueue();		
	q1.enqueue(40);	q1.printQueue();		
	q1.enqueue(50);	q1.printQueue();		
	q1.enqueue(60);	q1.printQueue();

	cout<<q1.dequeue()<<"  |  ";q1.printQueue();		
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();		
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();		
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();		
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();		
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();		
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();		
	return 0;
}