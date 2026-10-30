Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8


//solution
 class Solution {
public:
    vector<string> result;

    void solve(int n, string curr, int open, int close) {
        if(curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }
        
        if(open < n) {
            curr.push_back('(');
            solve(n, curr, open+1, close);
            curr.pop_back();
        }
        if(close < open) {
            curr.push_back(')');
            solve(n, curr, open, close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(n, curr, 0, 0);

        return result;
    }
};
