#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void add(char ch);
/*
	{
		add(head, ch);
	}
*/
	bool find(char ch);
	void del(char ch)
	{
		del(head, ch);
	}

	friend ostream& operator<<(ostream& out, LinkedList& list);

private:
	//fill in your code here
	struct Node
	{
		char data;
		Node * next;
	};
	Node * head;
	//void add(char ch);//Node *& head, char ch);
	bool del(Node * head, char ch);
};

#endif // _LINKED_LIST_
