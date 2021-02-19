/*Given an unsorted integer array nums, find the smallest missing positive integer.
Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int *arr=new int[n];
        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0 && nums[i]<=n)
            {
                arr[nums[i]-1]=nums[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};
