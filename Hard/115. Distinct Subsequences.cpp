Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.


//solution
class Solution {
public:
    int dp[1001][1001];
    int solve(string& s, string& t, int m, int n) {
        if(n == 0)
            return dp[m][n] = 1;
        if(m == 0)
            return dp[m][n] = 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        if(s[m-1] == t[n-1])
            return dp[m][n] = solve(s, t, m-1, n) + solve(s, t, m-1, n-1);
        else
            return dp[m][n] = solve(s, t, m-1, n);
    }
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;
        memset(dp, -1, sizeof(dp));
        return solve(s, t, m, n);
    }
};

t.c. = o(n+m)
