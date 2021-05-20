class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        /*long int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int currSum=nums[i]+nums[j]+nums[k];
                    if(abs(target-res)>abs(target-currSum))
                    {
                        res=currSum;
                    }
                }
            }
        }
        return res;*/
        if(nums.size()<3)
            return 0;
        //using Two Pointer Method
        sort(nums.begin(),nums.end());
        //fix the first element of the possible triplet
        int sum=nums[0]+nums[1]+nums[2];
        for(int first=0;first<n-2;first++)
        {
            int s=first+1;
            int e=n-1;
            while(s<e)
            {
                int currSum=nums[first]+nums[s]+nums[e];
                if(abs(target-sum)>abs(target-currSum))
                    sum=currSum;
                else if(currSum>target)
                    e--;
                else if(currSum<target)
                    s++;
                else
                    return currSum;
            }
        }
        return sum;
        
    }
};
