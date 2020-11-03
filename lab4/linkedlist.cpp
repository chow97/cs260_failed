#include "linkedlist.h"

//implementations for the member functions of LinkedList class

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	Node * curr = head;
	while(curr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}

void LinkedList::add(int value)
{
	Node * curr = head;
	Node * newNode = new Node();
	newNode->value = value;
	newNode->next = nullptr;
	if(head == nullptr)
	{
		head = newNode;
		return;
	}
	while(curr->next != nullptr)
	{
		curr = curr->next;
	}
	curr->next = newNode;
}
/*
void LinkedList::add(int value)
{
	Node * curr = head;
	if(head == nullptr)
	{
		head = new Node(value, nullptr);
	}
	while(curr != nullptr)
	{
		curr = curr->next;
	}
	curr = new Node(value, nullptr);
}
*/
int LinkedList::sum()
{
	int total = 0;
	while(head != nullptr)
	{
		total += head->value;
		head = head->next;
	}
	return total;
}

int LinkedList::_sumR(Node* node)
{
	if(node != nullptr)
	{
		return node->value + _sumR(node->next);
	}
	else
	{
		return 0;
	}
}

ostream& operator<< (ostream& out, LinkedList& list)
{
	LinkedList::Node * curr = list.head;

	out << endl << "Displaying the List: " << endl;
	while(curr != nullptr)
	{
		out << curr->value << endl;
		curr = curr->next;
	}
	return out;
}

