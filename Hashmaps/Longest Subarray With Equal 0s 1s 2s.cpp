int longestSubarrayWithEqual0s1s2s(vector<int>& nums)
{
    int maxLen = 0;
    unordered_map<string,int> map;
    int count0=0,count1=0,count2=0;
    int delta10=count1-count0;
    int delta21=count2-count1;
    string key = delta21 + "#" + delta10;
    map.insert(make_pair(key,-1));
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            count0++;
        }
        else if(nums[i]==1){
            count1++;
        }
        else {
            count2++;
        }
        delta10=count1-count0;
        delta21=count2-count1;
        key = delta21 + "#" + delta10;
        if(map.find(key)!=map.end())
        {
            int prevIndex = map[key];
            int currLen = i - prevIndex;
            maxLen = max(maxLen,currLen);
        }
        else
        {
            map[key]=i;
        }
    }
    return maxLen;
}
