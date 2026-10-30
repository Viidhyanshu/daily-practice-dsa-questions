You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.

 

Constraints:

1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.




  //solution
  
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> low(26, false);
        vector<bool> up(26, false);
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                low[c - 'a'] = true;
            }
            else {
                up[c - 'A'] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (low[i] && up[i]) {
                ans++;
            }
        }
        return ans;
    }
};
