#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;

void fun(char *a)
{
    char *b[50];
    *b = a;
    cout<<endl<<*b;
}
int main()
{
    string *b;
    *b = new char[2];
    cin>>*b;
    cout<<endl<<*b;
    //fun(*b);
    return 0;
}