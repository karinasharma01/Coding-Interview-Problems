/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
*/

Notice that you may not slant the container.
#include<bits/stdc++.h>
int maxArea(vector<int>& height) {
    // Write your code here
    int n = height.size();
    int maxArea = INT_MIN;
    //sort(height.begin(),height.end());
    int i = 0,j=n-1;
    while(i < j)
    {
        int minHeight=min(height[i],height[j]);
        maxArea=max(maxArea,minHeight*(j-i));
        if(height[i]<height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return maxArea;
}
