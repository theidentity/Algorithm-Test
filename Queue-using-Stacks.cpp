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
		max = l;
		top = -1;
		a = new int [max];
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
		{
			printf("Stack is Empty\n");
			return -1;
		}
	}

	bool isFull()
	{
		return top == max - 1;
	}

	bool isEmpty()
	{
		return top == -1;
	}

	int getSize()
	{
		return top+1;
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
	Stack *s1,*s2;
public:
	Queue(int l=4)
	{
		s1=new Stack(l);
		s2=new Stack(l);
	}

	void enqueue(int v)
	{
		if(!s1->isFull())
			s1->push(v);
		else
			printf("Queue Overflow\n");
	}

	int dequeue()
	{
		if(s1->isEmpty())
			return -1;
		while(s1->getSize()!=1)
			s2->push(s1->pop());
		int v=s1->pop();
		while(!s2->isEmpty())
			s1->push(s2->pop());
		return v;
	}

	void printQueue()
	{
		if(!s1->isEmpty())
			s1->printStack();
		else
			printf("Queue is Empty\n");
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

	cout<<q1.dequeue()<<"  |  ";q1.printQueue();
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();
	cout<<q1.dequeue()<<"  |  ";q1.printQueue();

	return 0;
}