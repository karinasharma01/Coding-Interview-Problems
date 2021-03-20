/*Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Example 1:

Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)
Example 2:

Input:
n = 5
A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the 
subarray is (3,4).
Your Task:
You don't need to read input or print anything.
Your task is to complete the function countSubarrWithEqualZeroAndOne() which takes the array arr[] and the size of the array as inputs and returns 
the number of subarrays with equal number of 0s and 1s.
Constraints:
1 <= n <= 106
0 <= A[i] <= 1
*/
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        long long int count = 0;
        unordered_map<int,int> map;
        //map is used to store the no of times (frequency) of how many times
        //a particular sum occurs
        //take 0 as -1 & 1 as 1
        map.insert(make_pair(0,1));
        //frequency of sum 0 is initially 1
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                sum+=-1;
            }
            else if(arr[i]==1)
            {
                sum+=1;
            }
            if(map.find(sum)!=map.end())
            {
                count+=map[sum];
                map[sum]++;
            }
            else
            {
                map[sum]=1;
            }
        }
        return count;
    }
};
