/*Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> m;
        m.insert(make_pair(0,1));
        int sum = 0;
        for(int i=0;i<=nums.size()-1;i++)
        {
            sum+=nums[i];
            int remSum = sum-k;
            if(m.find(remSum)!=m.end())
            {
                ans+=m[remSum];
            }
            m[sum]=m[sum]+1;
        }
        return ans;
    }
};
