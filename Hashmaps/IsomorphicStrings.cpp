/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        //this map1 keeps a track of which character of string s is mapped to which
        //char of string t
        unordered_map<char,char> map1;
        //this is used to keep a track of whether a char in string t has already
        //been mapped to a character in string s or not
        unordered_map<char,bool> map2;
        
        for(int i=0;i<s.length();i++)
        {
            char c1 = s[i];
            char c2 = t[i];
            //check if c1 is already present in map1 or not
            if(map1.find(c1)!=map1.end())
            {
                //if present check whether it is mapped to the corresponding char c2
                //in target string t or not
                if(map1[c1]!=c2)
                    return false;
            }
            else
            {
                //check whether c2 has been used or not
                if(map2.find(c2)!=map2.end())
                {
                    return false;
                }
                else
                {
                    map1[c1]=c2;
                    map2[c2]=true;
                }
            }
        }
        return true;
    }
};
