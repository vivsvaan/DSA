#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <string.h>

using namespace std;

struct node
{
	struct node* next;
	int data;
	node* createnode(int i);
	

}*head;

node* node::createnode(int i)
{
    struct node *n, *newn;
    if(head == NULL)
    {
        newn = new(struct node);
        newn->next = NULL;
        newn->data = i;
        head = newn;
        head->next = NULL;
        return newn;
    }
    else{
    n = head;
    while(n->next !=NULL)
    {
        n = n->next;
    }
    newn = new(struct node);
    newn->next = NULL;
    newn->data = i;
    n->next = newn;
    return newn;
    }
 }


int main()
{
	struct node *ptr1, *ptr2, n;
	int i;
	for(i=0;i<10;i++)
	{
		ptr1 = n.createnode(i);
	}

	//display
	ptr1 = head;
	while(ptr1 != NULL)
	{
		cout<<ptr1->data<<endl;
		ptr1 = ptr1->next;
	}

	//delete from end
	cout<<endl<<endl;
	ptr1 = head;
	while(ptr1->next !=NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		//cout<<ptr2->data<<"\t"<<ptr1->data<<endl;
	}
	ptr1 = NULL;
	ptr2->next = NULL;
	

	return 0;
}


























