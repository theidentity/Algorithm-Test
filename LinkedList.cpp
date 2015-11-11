#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

struct node
{
	int val;
	node * next;
};

class LinkedList
{
	int count, max;
	node *H;

public:
	LinkedList(int l = 0)
	{
		H = createNode();
		count = 0;
		max = l;
	}
	void freeLinkedList()
	{
		node *tmp;
		tmp = H;
		while (tmp != NULL)
		{
			node *toDelete = tmp;
			tmp = tmp->next;
			delete(toDelete);
		}
		H = NULL;
	}
	node* createNode(int v = -1)
	{
		node* tmp = (node*)malloc(sizeof(node));
		tmp->next = NULL;
		tmp->val = v;
		return tmp;
	}

	node* getHead()
	{
		return H;
	}

	void insertAtEnd(int v)
	{
		node *tmp = createNode(v);
		node *p = H->next;
		if(p==NULL)
		{
			H->next=tmp;
			count++;
			return;
		}
		while (p->next != NULL)
			p = p->next;
		p->next = tmp;
		count++;
	}

	void insertAtFront(int v)
	{
		node *tmp = createNode(v);
		tmp->next = H->next;
		H->next = tmp;
		count++;
	}

	int deleteAtFront()
	{
		if (H->next == NULL)
		{
			printf("List is Empty\n");
			return -1;
		}
		node *tmp = H->next;
		H->next = tmp->next;
		int v = tmp->val;
		delete(tmp);
		count--;
		return v;
	}

	int deleteAtRear()
	{
		if (H->next == NULL)
		{
			printf("List is Empty\n");
			return -1;
		}

		node *p = H->next;
		if (p->next == NULL)
		{
			H->next = NULL;
			int v = p->val;
			delete(p);
			count--;
			return v;
		}
		else
		{
			while (p->next->next != NULL)
				p = p->next;
			node *tmp = p->next;
			int v = tmp->val;
			p->next = NULL;
			delete(tmp);
			count--;
			return v;
		}


	}


	void printList()
	{
		if (H == NULL || H->next == NULL)
		{
			printf("List is Empty\n");
			return;
		}
		node *p = H->next;
		while (p != NULL)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	void printReverseRecursively(node* frontNode)
	{
		if (frontNode == NULL)
			return;
		else
			printReverseRecursively(frontNode->next);
		cout << frontNode->val << " ";

	}

	void printMiddleElement()
	{
		int middle = count % 2 != 0 ? count / 2 : (count + 1) / 2;
		node *p = H->next;
		while (middle != 0)
		{
			if (p == NULL)
				return;
			p = p->next;
			middle--;
		}
		cout << "Middle Element is : " << p->val << endl;
	}

	void printMiddleElementUsingSlowPointer()
	{
		if (H->next == NULL)
		{
			printf("LinkedList is Empty\n");
			return;
		}
		node *slowptr = H->next;
		node *fastptr = H->next;
		while (fastptr != NULL)
		{
			fastptr = fastptr->next;
			if (fastptr != NULL)
			{
				fastptr = fastptr->next;
				slowptr = slowptr->next;
			}
		}
		cout << "Middle Element is : " << slowptr->val << endl;
	}

	void printNthElementUsingPtr(int n)
	{
		if (H -> next == NULL)
		{
			printf("LinkedList is Empty\n");
			return;
		}

		node *pfront = H->next;
		node *prear = H->next;
		int tmpcnt = n;
		while (tmpcnt)
		{
			if (prear == NULL)
			{
				printf("Not enough Nodes\n");
				return;
			}
			else
			{
				prear = prear->next;
				tmpcnt--;
			}
		}

		while (prear != NULL)
		{
			prear = prear->next;
			pfront = pfront->next;
		}
		printf("Element at %d is %d \n", n, pfront->val );

	}

	void copyLinkedList(LinkedList l1)
	{
		node *p=l1.H->next;
		while(p!=NULL)
		{
			insertAtFront(p->val);
			p=p->next;
		}
	}
};

int main()
{
	node *header;
	LinkedList l1,l2;
	header = l1.getHead();
	l1.insertAtFront(10); l1.printList();
	l1.insertAtFront(20); l1.printList();
	l1.insertAtFront(30); l1.printList();
	l1.insertAtFront(40); l1.printList();
	l1.insertAtFront(50); l1.printList();
/*	l1.insertAtEnd(11);l1.printList();
	l1.insertAtEnd(21);l1.printList();
	l1.insertAtEnd(31);l1.printList();
	l1.insertAtEnd(41);l1.printList();
	l1.insertAtEnd(51);l1.printList();*/

	// cout<<l1.deleteAtFront()<<" | ";l1.printList();
	// cout<<l1.deleteAtRear()<<" | ";l1.printList();
	// l1.printReverseRecursively(header->next);	cout<<endl;
	// l1.printMiddleElement();
	// l1.printMiddleElementUsingSlowPointer();
	// l1.freeLinkedList();	l1.printList();
	// l1.printNthElementUsingPtr(5);
	// l1.printNthElementUsingPtr(6);
	l2.copyLinkedList(l1);
	l2.printList();

}