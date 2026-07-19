Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

  //solution
  
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string result;
        vector<bool> taken(26, false);
        vector<int> lastIdx(26);

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            lastIdx[ch - 'a'] = i;
        }
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (taken[idx] == true)
                continue;
            while (result.length() > 0 && s[i] < result.back() &&
                   lastIdx[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(s[i]);
            taken[idx] = true;
        }
        return result;
    }
};

t.c. = o(n)
