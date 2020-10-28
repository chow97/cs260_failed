#include "dlist.h"

//put the implmenetation of the required functions here
int countEven(node * head)
{
	int count = 0;
	if(head == nullptr)
	{
		return count;
	}
	if(head->data % 2 == 0)
	{
		return count + 1;
	}
	else
	{
		return countEven(head->next);
	}
}
