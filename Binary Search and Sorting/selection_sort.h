#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;

int smallest(int arr[], int k, int n);
void selection_sort(int arr[],int n)
{
	int i,k, pos, temp;
	for(k=0;k<n;k++)
		{
			pos = smallest(arr, k, n);
			temp = arr[k];
			arr[k] = arr[pos];
			arr[pos] = temp;
		}
	cout<<"\n The array sorted in ascending order is :\n"<<endl;
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\t";
	cout<<endl;
	system("pause");
}
  
int smallest(int arr[], int k, int n)
{
	int pos = k, small=arr[k], i;
	for(i=k+1;i<n;i++)
		{
			if(arr[i]< small)
				{
					small = arr[i];
					pos = i;
				}
		} 
	return pos;
}


