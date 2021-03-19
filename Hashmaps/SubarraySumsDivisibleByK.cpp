/*Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0;
        unordered_map<int,int> m;
        //hashmap used to store the frequencies of remainder
        int sum = 0;
        int rem = 0;
        m.insert(make_pair(0,1));
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            rem = sum % K;
            if(rem < 0)
            {
                rem=rem+K;
            }
            if(m.find(rem)!=m.end())
            {
                ans+=m[rem];
                m[rem]++;
            }
            else
            {
                m[rem]=1;
            }
        }
        return ans;
    }
};
