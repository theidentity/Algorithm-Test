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

class Queue
{
	node *front, *rear;
	int max;
	int count;
public:
	Queue(int l = 4)
	{
		max = l;
		count = 0;
		front = NULL;
		rear = NULL;
	}

	node * createNode(int v)
	{
		node *tmp;
		tmp = (node *)malloc(sizeof(node));
		tmp->val = v;
		tmp->next = NULL;
	}

	void enqueue(int v)
	{
		if (!isFull())
		{
			node *tmp = createNode(v);
			if (front == NULL && rear==NULL)
			{
				front = tmp;
				rear = tmp;
			}
			else
			{
				rear->next = tmp;
				rear = tmp;
			}
			count++;

		}
		else
		{
			printf("Queue is Full\n");
		}
	}

	int dequeue()
	{
		if (!isEmpty())
		{
			int v = front->val;
			front = front->next;
			count--;
			return v;
		}
		else
			printf("Queue is Empty\n");
		return -1;
	}
	bool isEmpty()
	{
		return count == 0;
	}

	bool isFull()
	{
		return count == max ;
	}

	int getSize()
	{
		return count;
	}


	void printQueue()
	{
		cout<<getSize()<<"  |  ";
		if(!isEmpty())
		{
			node *tmp=front;
			while(tmp!=NULL)
			{
				cout<<tmp->val<<" ";
				tmp=tmp->next;
			}
			cout<<endl;
		}
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

	cout << q1.dequeue() << "  |  "; q1.printQueue();
	cout << q1.dequeue() << "  |  "; q1.printQueue();
	cout << q1.dequeue() << "  |  "; q1.printQueue();
	cout << q1.dequeue() << "  |  "; q1.printQueue();
	return 0;
}