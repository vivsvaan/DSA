#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

using namespace std;

struct stak
{
    int data;
    struct stak *next;
    stak *top = NULL;
    stak *push(struct stak *, int);
    stak *display(struct stak *);
    stak *pop(struct stak *);
};

stak *stak::push(struct stak *top, int val)
{
    struct stak *ptr;
    ptr = (struct stak*)malloc(sizeof(struct stak));
    ptr -> data = val;
    if(top == NULL)
    {
        ptr -> next = NULL;
        top = ptr;
    }
    else
    {
        ptr -> next = top;
        top = ptr;
    }
    return top;
}

stak *stak::display(struct stak *top)
{
    struct stak *ptr;
    ptr = top;
    if(top == NULL)
        cout<<"\n STACK IS EMPTY";
    else
    {
        while(ptr != NULL)
        {
            cout<<"\n"<<ptr->data;
            ptr = ptr->next;
        }
    }
    return top;
}

stak *stak::pop(struct stak *top)
{
    struct stak *ptr;
    ptr = top;
    if(top == NULL)
        cout<<"\n STACK UNDERFLOW";
    else
    {
        top = top->next;
        cout<<"\n the value being deleted is: "<<ptr->data;
        free(ptr);
    }
    return top;
}


int peek(struct stak *top)
{
    if(top == NULL)
        return -1;
    else
        return top->data;
}

int main()
{
    int val, option;
    do{
        cout<<"\n*****MAIN MENU*****\n"
        <<"\n1. PUSH"
        <<"\n2. POP"
        <<"\n3. PEEK"
        <<"\n4. DISPLAY"
        <<"\n5. EXIT"
        <<"\n Enter your Option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"\nEnter the no. to be pushed on stack: ";
            cin>>val;
            top = push(top, val);
            cout<<"\nno. pushed successfully\n";
            system("pause");
            break;

        case 2:
            top = pop(top);
            system("pause");
            break;

        case 3:
            val = peek(top);
            if(val !- -1)
                cout<<"\n The value at the top of stack is: "<<val;
            else
                cout<<"\n STACK IS EMPTY";
            break;

        case 4:
            top = display(top);
            system("pause");
            break;
        }
    }while(option != 5);
    return 0;

}
