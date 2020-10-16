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

void LinkedList::add(char ch)
{
	Node * newNode = new Node();
	Node * last = nullptr;
	newNode->data = ch;
	newNode->next = nullptr;
	if(head == nullptr)
	{
		head = newNode;
		return;
	}
	last = head;
	while(last->next != nullptr)
	{
		last = last->next;
	}
	last->next = newNode;
}

bool LinkedList::find(char ch)
{
	Node * curr = head;
	while(curr != nullptr)
	{
		if(curr->data == ch)
		{
			return true;
		}
		curr = curr->next;
	}
	return false;
}

bool LinkedList::del(char ch)
{
	Node * curr = head;
	while(curr != nullptr)
	{
		Node * temp = curr;
		if(curr->data == ch)
		{
			curr = curr->next;
			delete temp;
			return true;
		}
		curr = curr->next;
	}
	return false;
}

ostream& operator<< (ostream& out, const LinkedList& list)
{
	LinkedList::Node * curr = list.head;

	out << endl << "Displaying the List: " << endl;
	while(curr != nullptr)
	{
		out << curr->data << endl;
		curr = curr->next;
	}
	return out;
}

