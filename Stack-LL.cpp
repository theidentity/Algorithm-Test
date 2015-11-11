#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

struct node
{
	int val;
	struct node* next;
};

class Stack
{
	node *top;
	int count;
	int max;
public:
	Stack(int l = 5)
	{
		top = NULL;
		count = 0;
		max = l;
	}

	node * createNode(int v)
	{
		node *tmp;
		tmp = (node *)malloc(sizeof(node));
		tmp->val = v;
		tmp->next = NULL;
	}

	void push(int v)
	{
		if (!isFull())
		{
			node *tmp = createNode(v);
			if(top==NULL)
				top=tmp;
			else
			{
				tmp->next = top;
				top=tmp;
			}
			count++;
		}
		else
			printf("Stack Overflow\n");
	}

	int pop()
	{
		if (!isEmpty())
		{
			int v = top->val;
			top = top->next;
			count--;
			return v;
		}
		else
		{
			printf("Stack Underflow\n");
			return -1;
		}
	}

	bool isFull()
	{
		return count == max - 1;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	int getSize()
	{
		return count;
	}
	void printStack()
	{
		cout << "Size : " << getSize() << "  ||  ";
		if (!isEmpty())
		{
			node *tmp = top;
			while (tmp != NULL)
			{
				cout << tmp->val << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
		else
			printf("Stack is Empty\n");
	}

};

int main()
{
	Stack s1(5);	s1.printStack();
	s1.push(10);	s1.printStack();
	s1.push(20);	s1.printStack();
	s1.push(30);	s1.printStack();
	s1.push(40);	s1.printStack();
	s1.push(50);	s1.printStack();
	s1.push(60);	s1.printStack();
	s1.push(70);	s1.printStack();

	cout << s1.pop() << "   ||    "; s1.printStack();
	cout << s1.pop() << "   ||    "; s1.printStack();
	cout << s1.pop() << "   ||    "; s1.printStack();
	cout << s1.pop() << "   ||    "; s1.printStack();
	cout << s1.pop() << "   ||    "; s1.printStack();
	cout << s1.pop() << "   ||    "; s1.printStack();
	cout << s1.pop() << "   ||    "; s1.printStack();

	return 0;
}