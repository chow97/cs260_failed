#include "linkedlist.h"

//implementations for the member functions of LinkedList class

LinkedList::LinkedList()
{
	head = nullptr;
}

void add(char ch)
{

}

bool find(char ch)
{

}

bool del(char ch)
{

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

