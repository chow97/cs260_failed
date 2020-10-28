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
	bool find(char ch);
	bool del(char ch);

	friend ostream& operator<<(std::ostream& out, LinkedList& list);

private:
	//fill in your code here
	struct Node
	{
		char data;
		Node * next;
	};
	Node * head;
	bool del(Node * curr, char ch);
};

#endif // _LINKED_LIST_
