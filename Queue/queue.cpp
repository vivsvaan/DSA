#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;
int const size=100;
int frnt=-1,rear=-1,flag=0;
int queue[size];

void create()
{
	if(frnt!=-1)
	{
	    cout<<"Queue is already Created\n";
	    system("pause");
	}
	else
	{
		frnt=0;
		cout<<"\n Queue Created\n";
		system("pause");
	}

}

void insertq(int q[],int n)
{
	if(frnt==-1)
	{
		cout<<"\nQueue is not created\n";
		system("pause");
	}
	else if(rear==n-1)
	{
		cout<<"\nQueue is full\n";
		system("pause");
	}
	else
	{
		int data;
		cout<<"Enter integer data:";
		cin>>data;
		rear++;
		q[rear]=data;
		cout<<"\nItem inserted\n";
		system("pause");
	}
}

void deleteq(int q[])
{
	int i,item;
	if(rear==-1)
	{
		cout<<"\nStack is empty\n";
		system("pause");
	}
	else if(frnt==rear)
	{	item=q[rear];
	frnt=-1;
	rear=-1;
	cout<<"\nItem removed = "<<item<<"\nQueue Deleted\n";
	system("pause");
	}
	else
	{	item=q[frnt];
		frnt++;
		cout<<"\nItem Deleted="<<item<<endl;
		system("pause");
	}

}
void display(int q[])
{
	int i,temp=rear;
	for(i=frnt;i<=temp;i++)
	{
		cout<<q[i]<<" ";
	}
	cout<<endl;
	system("pause");
}


int main()
{
	int data;
	char choic;
	int n;
	cout<<"Enter Size of Queue\n";
	cin>>n;
	cout<<endl;
	while(1)
        {
            system("cls");

            cout<<"1. Create \n"
            <<"2. Insert \n"
            <<"3. Delete \n"
            <<"4. Display\n"
            <<"5. Exit\n";
            fflush(stdin);
            choic = getche();
            cout<<endl;
            switch(choic)
            {
            case '1':
                create();
                break;

            case '2':
                insertq(queue,n);
                break;

            case '3':
                deleteq(queue);
                break;

            case '4':
                display(queue);
                break;

            case '5':
                exit(1);

            }
}
}
