You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

 

Example 1:

Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
Example 2:

Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.
 

Constraints:

n == s1.length == s2.length
1 <= n <= 105
s1 and s2 consist only of lowercase English letters.


  //solution
  class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        map<char,int>st1,st2,st3,st4;
        for(int i=0;i<n;i++){
            if(i&1){
                st1[s1[i]]++;
                st3[s2[i]]++;
            }
            else{
                st2[s1[i]]++;
                st4[s2[i]]++;
            }
        }
        if(st1==st3 && st2==st4){
            return true;
        }
        return false;
    }
};

