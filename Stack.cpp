#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX=10;

class Stack
{
	int top;
	int *a;
	int limit;
public:
	Stack(int l=MAX)
	{
		limit=l-1;
		a=new int[limit];
		top=-1;
	}

	void push(int v)
	{
		if(!isFull())
			a[++top]=v;
		else
			printf("Stack is full\n");
	}

	int pop()
	{
		if(!isEmpty())
			return a[top--];
		else
			printf("Stack is Empty\n");
	}

	bool isEmpty()
	{
		return top==-1;
	}

	bool isFull()
	{
		return top>=limit;
	}

	void print()
	{
		if(isEmpty())
			printf("Stack is Empty\n");
		else{
			for(int i=0;i<=top;i++)
				cout<<a[i]<<"  ";
		}
			cout<<endl<<"top is "<<peek()<<" size is "<<sizeofstack()<<endl;

		
	}

	void generate(int upto)
	{
		for(int i=0;i<upto;i++)
			a[i]=rand()%10+1;
	}

	int peek()
	{
		return a[top];
	}

	int sizeofstack()
	{
		return top+1;
	}
};

int main()
{
	Stack S1(5);S1.print();
	S1.push(10);	S1.print();
	S1.push(20);	S1.print();
	S1.push(30);	S1.print();
	S1.push(40);	S1.print();
	S1.push(50);	S1.print();
	S1.push(60);	S1.print();
	S1.push(70);	S1.print();
	S1.pop();	S1.print();
	S1.pop();	S1.print();
	S1.pop();	S1.print();
	S1.pop();	S1.print();
	S1.pop();	S1.print();
	S1.pop();	S1.print();
	S1.pop();	S1.print();
	return 0;
}