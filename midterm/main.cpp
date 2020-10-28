#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

	cout << "even: " <<	countEven(head);

    display(head);
    destroy(head);    
    return 0;
}
