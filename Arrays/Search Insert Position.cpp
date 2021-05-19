//Method - 1 
//Using Linear Search
//Time Complexity:O(n)
//Space Complexity:O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                index=i;
                break;
            }
        }
        if(index!=-1)
            return index;
        //if index not found then we'll calculate it if inserted in order
        //the element would be inserted just before the number greater than it in the array
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>target)
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            //insert the element at last
            index=nums.size();
        }
        return index;
    }
};


//Method-2
//O(log n) Time Complexity

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //O(log n) solution
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return start;
    }
};
