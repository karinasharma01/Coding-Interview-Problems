/*Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104
*/
class Solution {
public:
    int numSquares(int n) {
        //if given number n is perfect square then minimum number of 
        //perfect square numbers that sum to n = 1
        /*if(sqrt(n)-floor(sqrt(n))==0)
            return 1;
        if(n<=3)
            return n;
        int minSquares = n;
        for(int i=1;i<=n;i++)
        {
            int temp=i*i;
            if(temp>n)
            {
                break;
            }
            else
            {
                minSquares=min(minSquares,1+numSquares(n-temp));
            }
        }
        return minSquares;*/
        int *minSquares = new int[n+1];
        minSquares[0]=0;
        minSquares[1]=1;
        for(int i=2;i<=n;i++)
        {
            int min=INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                int rem=i-j*j;
                if(minSquares[rem]<min)
                {
                    min=minSquares[rem];
                }
            }
            minSquares[i]=min+1;
        }
        return minSquares[n];
    }
};
