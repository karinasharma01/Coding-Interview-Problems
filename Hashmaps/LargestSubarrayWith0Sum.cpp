/*Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/
#include<iostream>
#include <unordered_map>
using namespace std;
int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> map;
    //this unordered map is used to store the sum till the ith index 
    //for every index i in the given array
    int i = -1;
    int sum = 0;
    int maxLen = 0;
    map.insert(make_pair(sum,i));
    while(i < n - 1)
    {
        i++;
        sum+=A[i];
        //if the sum calculated does not exist
        if(map.find(sum)==map.end())
        {
            map[sum]=i;
        }
        else
        //if the sum previously occured then length of the subarray with sum = 0
        //is equal to the difference between the index i and the index of the previous
        //index at which the sum occured
        {
            int currLen = i - map[sum];
            if(currLen > maxLen)
            {
                maxLen = currLen;
            }
        }
    }
    return maxLen;
}
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0;i<n;i++)
    {
      cin>>A[i];
    }
    cout<<maxLen(A,n)<<endl;
  }
  return 0;
}
