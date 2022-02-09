#include <iostream>
#include <vector>
using namespace std;
int countMinOperations(vector<int>& arr)
{
    int n = arr.size();
    //we need to obtain the given array target from an array of n integers where all the elements are initially zero in minimum operations
    //we can perform 2 operations on the array
    //1.Increment any one element of the array by one 2.Double all the elements of the array
    int res = 0;
    while(1)
    {
        int count0 = 0;
        //first find the first odd element in the array
        int i;
        for(i=0;i<n;i++)
        {
            if(arr[i] & 1)
            {
                break;
            }
            else if(arr[i]==0)
            {
                count0++;
            }
        }
        //if all the numbers in the given array are even then we'll divide each number by 2 & increment res by 1
        
        //if all numbers have been reduced to zero return the min operations res
        if(count0==n)
        {
            return res;
        }
        if(i==n)
        {
            for(int j=0;j<n;j++)
            {
                arr[j] = arr[j]/2;
            }
            res++;
        }
        for(int j=i;j<n;j++)
        {
            if(arr[j] & 1)
            {
                arr[j]--;
                res++;
            }
        }
    }
    
}
int main() {
	// your code goes here
	vector<int> arr = {1,5,4,8};
	int minOperations =  countMinOperations(arr);
	cout<<"Minimum operations to obtain the target array is : " << minOperations << endl;
	return 0;
}
