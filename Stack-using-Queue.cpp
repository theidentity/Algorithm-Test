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

class Stack
{
	Queue *q1;
	Queue *q2;
public:
	Stack(int l=4)
	{
		q1=new Queue(l);
		q2=new Queue(l);
	}

	void push(int v)
	{
		if(!q1->isFull())
			q1->enqueue(v);
		else
			printf("Stack overflow\n");
	}

	int pop()
	{
		if(q1->isEmpty())
		{
			printf("Stack underflow\n");
			return -1;
		}

		while(q1->getSize()!=1)
		{
			q2->enqueue(q1->dequeue());
		}
		int v=q1->dequeue();
		while(!q2->isEmpty())
		{
			q1->enqueue(q2->dequeue());
		}
		return v;
	}

	void printStack()
	{
		if(!q1->isEmpty())
			q1->printQueue();
		else
			printf("Stack is Empty\n");
	}
};

int main()
{
	//Stack using Queue
	Stack s1(4);	s1.printStack();
	s1.push(10);	s1.printStack();
	s1.push(20);	s1.printStack();
	s1.push(30);	s1.printStack();
	s1.push(40);	s1.printStack();
	s1.push(50);	s1.printStack();
	s1.push(60);	s1.printStack();
		
	cout<<s1.pop()<<"  |  ";	s1.printStack();
	cout<<s1.pop()<<"  |  ";	s1.printStack();
	cout<<s1.pop()<<"  |  ";	s1.printStack();
	cout<<s1.pop()<<"  |  ";	s1.printStack();
	cout<<s1.pop()<<"  |  ";	s1.printStack();
	cout<<s1.pop()<<"  |  ";	s1.printStack();

	return 0;
}