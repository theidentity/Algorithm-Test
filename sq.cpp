#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Stack
{
	int top;
	int *a;
	int max;
public:
	Stack(int l = 5)
	{
		max = l - 1;
		top = -1;
		a = new int [l];
	}

	void push(int v)
	{
		if (!isFull())
		{
			top++;
			a[top] = v;
		}
		else
			printf("Stack is Full\n");
	}

	int pop()
	{
		if (!isEmpty())
		{
			int v = a[top];
			top--;
			return v;
		}
		else
			printf("Stack is Empty\n");
	}

	bool isFull()
	{
		return top == max;
	}

	bool isEmpty()
	{
		return top == -1;
	}

	void printStack()
	{
		if (!isEmpty())
		{
			for (int i = 0; i <= top; i++)
				cout << a[i] << " ";
			cout << endl;
		}
		else
			printf("Stack is Empty\n");
	}

};

class Queue
{
	int *a;
	int front, rear;
	int max;

public:
	Queue(int l = 4)
	{
		max = l - 1;
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
			rear = (rear + 1) % (max + 1);
			a[rear] = v;
		}
		else
		{
			printf("Queue is Full\n");
		}
	}

	int dequeue()
	{
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		if (!isEmpty())
		{

			int v = a[front];
			front = (front + 1) % (max + 1);
			return v;
		}
		else
			printf("Queue is Empty\n");
	}
	bool isEmpty()
	{
		return (front == -1 && rear == -1);
	}

	bool isFull()
	{
		return (abs(front - rear) == max);
	}

	void printQueue()
	{
		cout << front << " " << rear << endl;
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
	Queue q(5);	q.printQueue();
	q.enqueue(10);	q.printQueue();
	q.enqueue(20);	q.printQueue();
	q.enqueue(30);	q.printQueue();
	q.enqueue(40);	q.printQueue();
	q.enqueue(50);	q.printQueue();
	q.enqueue(60);	q.printQueue();

	q.dequeue();	q.printQueue();
	q.dequeue();	q.printQueue();
	q.dequeue();	q.printQueue();
	q.dequeue();	q.printQueue();
	q.dequeue();	q.printQueue();
	q.dequeue();	q.printQueue();



	return 0;
}