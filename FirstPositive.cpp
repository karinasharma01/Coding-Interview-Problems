/*
You are given an array of integers of length N, find the first missing positive integer in linear time and constant space.
In other words, find the lowest positive integer that does not exist in the array. The array can negative numbers as well.
For example, the input [3, 4, -1, 1] should give output 2 because it is the smallest positive number that is missing in the input array.
*/
#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int segregateNumbers(int arr[],int n)
{
    int j = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<=0)
        {
            swap(&arr[i],&arr[j]);
            j++;
        }
    }
    return j;
}
int firstPositiveMissing(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if (abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            return i+1;
        }
    }
    return n+1;
}
int firstMissing(int arr[], int n)
{
    // Write your code here.
    int shift = segregateNumbers(arr,n);
    return firstPositiveMissing(arr+shift,n-shift);
}
