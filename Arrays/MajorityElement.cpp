#include<bits/stdc++.h>
bool isMajorityElement(int arr[],int n,int ele)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            count++;
        }
    }
    if(count>floor(n/2))
    {
        return 1;
    }
    return 0;
}
int findMajorityElement(int arr[], int n)
{
	// Write your code here
    /*int ans = 0;
    int flag = 0;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    {
        map[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(map[arr[i]]>floor(n/2))
        {
            ans = arr[i];
            flag = 1;
        }
    }
    if(flag==1)
    {
        return ans;
    }
    return -1;*/
    //using Moore's Voting Algorithm
    int majorI = 0,count = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[majorI])
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count==0)
        {
            majorI = i;
            count = 1;
        }
    }
    if(isMajorityElement(arr,n,arr[majorI]))
    {
        return arr[majorI];
    }
    return -1;
}
