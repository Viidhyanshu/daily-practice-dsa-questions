Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 

Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:

The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
Example 2:

Input: s = "aaaa"

Output: 2

Explanation:

The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 

Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.


//solution
class Solution {
public:
    int maximumLengthSubstring(string s) {
        array<int, 26> count{};
        int left = 0;
        int res = 0;
        for (int right = 0; right < s.length(); ++right) {
            int ch = s[right] - 'a';
            ++count[ch];
            while (count[ch] > 2) {
                const int ch2 = s[left] - 'a';
                --count[ch2];
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

t.c. = o(n)

