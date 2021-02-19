//Solution to the Leetcode Problem Maximum Subarray 
//The problem has been solved using Kadane's Algorithm
/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = INT_MIN;
        int maxEndingHere = 0;
        for(int i = 0;i<nums.size();i++)
        {
            maxEndingHere = maxEndingHere + nums[i];
            maxSoFar = max(maxSoFar,maxEndingHere);
            if(maxEndingHere < 0)
            {
                maxEndingHere = 0;
            }
        }
        return maxSoFar;
    }
};
