/*For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced.
The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
*/
#include <iostream>
#include <stack>
using namespace std;
int countBracketReversals(string input)
{
    int len = input.length();
    if(len==0)
    return 0;
    if(len % 2!=0)
    {
        return -1;
    }
    stack<char> s ;
    for(int i=0;i<len;i++)
    {
        if(input[i]=='{')
        {
            s.push(input[i]);
        }
        else
        {
            if(!s.empty() && s.top()=='{')
            {
                s.pop();
            }
            else
            {
                s.push(input[i]);
            }
        }
    }
    //the stack consists of only the unbalanced expression
    int count = 0;
    while(!s.empty())
    {
        char c1 = s.top();
        s.pop();
        char c2 = s.top();
        s.pop();
        if(c1!=c2)
        {
            count+=2;
        }
        else
        {
            count+=1;
        }
        
    }
    return count;
}
int main() {
	// your code goes here
	string input;
	cin>>input;
	cout<<countBracketReversals(input)<<endl;
	return 0;
}

