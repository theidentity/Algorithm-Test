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
		cout<<"Size : "<<getSize()<<"  ||  ";
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

int main()
{
	Stack s1(5);
	s1.push(10);	s1.printStack();
	s1.push(20);	s1.printStack();
	s1.push(30);	s1.printStack();
	s1.push(40);	s1.printStack();
	s1.push(50);	s1.printStack();
	s1.push(60);	s1.printStack();
	s1.push(70);	s1.printStack();

	cout<<s1.pop()<<"   ||    ";s1.printStack();
	cout<<s1.pop()<<"   ||    ";s1.printStack();
	cout<<s1.pop()<<"   ||    ";s1.printStack();
	cout<<s1.pop()<<"   ||    ";s1.printStack();
	cout<<s1.pop()<<"   ||    ";s1.printStack();
	cout<<s1.pop()<<"   ||    ";s1.printStack();
	cout<<s1.pop()<<"   ||    ";s1.printStack();
	
	return 0;
}