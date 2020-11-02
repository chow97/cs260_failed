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
/*
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
*/
void LinkedList::add(char ch)
{
	Node * curr = head;
	Node * newNode = new Node();
	newNode->data = ch;
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

/*
bool LinkedList::del(char ch)
{
	Node * curr = head;
	while(curr != nullptr)
	{
		Node * temp = curr;
		if(curr->next->data == ch)
		{
			temp = curr->next;
			curr = curr->next->next;
			delete temp;
			return true;
		}
		curr = curr->next;
	}
	return false;
}
bool LinkedList::del(char ch)
{
	Node * curr = head;
	Node * temp = curr;
	if(head->data == ch)
	{
		head = temp->next;
		curr = head;
		delete temp;
		return true;
	}
	while(temp != nullptr && temp->data != ch)
	{
		curr = temp;
		temp = temp->next;
	}
	curr->next = temp->next;
	delete temp;
	return true;
}
*/

bool LinkedList::del(Node * head, char ch)
{
	if(head == nullptr)
	{
		return false;
	}
	if(head->data == ch)
	{
		Node * temp = head;
		head = head->next;
		delete temp;
		return del(head, ch);
	}
	return del(head->next, ch);
}

ostream& operator<< (ostream& out, LinkedList& list)
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

