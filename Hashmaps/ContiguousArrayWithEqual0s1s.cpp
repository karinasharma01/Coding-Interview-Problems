/*Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //implementation using HashMaps
    int maxLen = 0;
        int sum = 0;
    //unordered map is used for storing the index for which a particular sum occurs
    unordered_map<int,int> map;
    //initially the sum is 0 which occurs at index =-1
    map.insert(make_pair(0,-1));
    for(int i = 0;i<nums.size();i++)
    {
        if(nums[i]==1)
        {
            sum+=1;
        }
        else if(nums[i]==0)
        {
            sum+=-1;
        }
        if(map.find(sum)!=map.end())
        {
            int prevIndex = map[sum];
            int currLen = i - prevIndex;
            if(currLen > maxLen)
            {
                maxLen = currLen;
            }
        }
        else
        {
            map[sum]=i;
        }
    }
    return maxLen;
    }
};
