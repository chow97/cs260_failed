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
		return count + 1 +  countEven(head->next);
	}
		return countEven(head->next);
}
