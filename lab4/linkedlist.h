#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(int value);

	int sum();				// sum of ints in list, calculated iteratively
	int sumR()
	{ 
		_sumR(head); 
	}				// sum of ints in list, calculated recursively

	friend ostream& operator<<(ostream& out, LinkedList& list);

private:
	struct Node
	{
//		Node(int value) : value(value), next(nullptr) {}
//		Node(int value, Node* next) : value(value), next(next) {}

		int		value;
		Node*	next;
	};

	int _sumR(Node* node);	// sum of ints in list, calculated recursively

	Node*	head;
};

#endif // _LINKED_LIST_
