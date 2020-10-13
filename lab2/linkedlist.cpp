#include "linkedlist.h"

//implementations for the member functions of LinkedList class

LinkedList::LinkedList()
{
	head = nullptr;
}

void LinkedList::add(char ch)
{
	Node * newNode = new Node();
	newNode->data = ch;
	newNode->next = head;
	head = newNode;

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
		if(curr->data == ch)
		{
			Node * temp = curr;
			curr = curr->next;
			delete temp;
			return true;
		}
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

