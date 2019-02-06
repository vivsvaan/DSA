#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include"bubble_sort.h"
#include"insertion_sort.h"
#include"selection_sort.h"
#include"binary_search.h"

using namespace std;

int main()
{
	int i, n, x, choice, result=0;
	cout<<"\nFirst let's make an Array\n"
	<<"\nEnter number of elements\n";
	cin>>n;
	int ar[n];
	cout<<"\nGood!...Now let's enter all "<<n<<" elements\n";
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
	}

	cout<<"\nArray created\n";
	system("pause");

	while(1)
	{
		system("cls");
		cout<<"\n1. Sort the array using BUBBLE Sort Algorithm"
		<<"\n2. Sort the array using INSERTION Sort Algorithm"
		<<"\n3. Sort the array using SELECTION Sort Algorithm"
		<<"\n4. Search an element using BINARY Search Algorithm"
		<<"\n5. Exit"
		<<"\n\n(Note:- To search an element using BINARY Search, you need to first sort the array)\n"
		<<"\nEnter your choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
			bubble_sort(ar, n);
			break;

			case 2:
			insertion_sort(ar, n);
			break;

			case 3:
			selection_sort(ar, n);
			break;

			case 4:
			cout<<"\nEnter element which is to be found\n";
			cin>>x;
			result = binary_search(ar, n, 0, n-1, x);
			(result == -1)? cout<<"\nElement is not present in array\n"
                 : cout<<"\nElement is present at index "<<result<<endl;
            system("pause");
			break;

			case 5:
			exit(0);

		}
	}

}