Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.



  //solution
  class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        int up = -1;
        char arr[n];
        for ( int i = 0; i < n; i++){
            char c = s[i];
            if (c=='(' || c=='{'|| c=='['){
                arr[++up]=c;
            }else{
                if(up == -1) return false;
                char last= arr[up--];
                if((c==')' && last != '(')|| (c=='}' && last != '{') || (c==']' && last != '['))
                return false;
            }
        }
        return up == -1;
    }
};

t.c. = o(n)
