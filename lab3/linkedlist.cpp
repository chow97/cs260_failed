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


void LinkedList::add(Node *& head, char ch)
{
	if(head == nullptr)
	{
		head = new Node();
		head->data = ch;
		head->next = nullptr;
	}
	else
	{
		add(head->next, ch);
	}
}
/*
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
*/


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
	Node * temp;
	if(head == nullptr)
	{
		return false;
	}
	if(head->data == ch)
	{
		delete head;
		return true;
	}
	if(head->next->data == ch)
	{
		temp = head->next;
		head->next = temp->next;
		delete temp;
		return true;
	}
	del(head->next, ch);
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

