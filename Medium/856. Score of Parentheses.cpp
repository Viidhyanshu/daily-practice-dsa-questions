Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
 

Constraints:

2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.


 //solution
 class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        if(n == 2) return 1;
        int score = 0 , depth = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') depth++;
            else {
                depth--;
                if(s[i-1] == '(') score += 1 << depth;
            }
        }
        return score;    
    }
};
