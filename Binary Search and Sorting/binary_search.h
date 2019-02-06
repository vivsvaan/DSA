#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;

int binary_search(int arr[], int n, int l, int r, int x)
{
   if (l <= r)
   {
        int mid = (l + r)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binary_search(arr, n, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binary_search(arr, n, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}