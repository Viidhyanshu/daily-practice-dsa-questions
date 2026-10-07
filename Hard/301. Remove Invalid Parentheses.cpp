Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
 

Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.


 //solution
 class Solution {
private:
    unordered_set<string> st;
    int n;
    void solve(const string& s, int i, string& curr, int count, int& maxLen) {
        if (count < 0)  
            return;
        if (i == n) {
            if (count == 0) {
                if (curr.length() > maxLen) {        
                    maxLen = curr.length();
                    st.clear();
                }
                if(curr.length() == maxLen) {
                    st.insert(curr);
                }
            }
            return;
        }
        if (s[i] != '(' && s[i] != ')') {                     
            curr.push_back(s[i]);
            solve(s, i + 1, curr, count, maxLen);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        solve(s, i + 1, curr, count + (s[i] == '(' ? 1 : -1), maxLen);
        curr.pop_back();
        solve(s, i + 1, curr, count, maxLen);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        int maxLen = 0;
        st.clear();
        string curr = "";
        solve(s, 0, curr, 0, maxLen);
        return vector<string>(begin(st), end(st));
    }
};
