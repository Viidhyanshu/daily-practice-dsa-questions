You are given two strings s and target, both having length n, consisting of lowercase English letters.

Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

 

Example 1:

Input: s = "abc", target = "bba"

Output: "bca"

Explanation:

The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
The lexicographically smallest permutation that is strictly greater than target is "bca".
Example 2:

Input: s = "leet", target = "code"

Output: "eelt"

Explanation:

The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
The lexicographically smallest permutation that is strictly greater than target is "eelt".
Example 3:

Input: s = "baba", target = "bbaa"

Output: ""

Explanation:

The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
None of them is lexicographically strictly greater than target. Therefore, the answer is "".
 

Constraints:

1 <= s.length == target.length <= 300
s and target consist of only lowercase English letters.
//solution
 class Solution {
public:
    string result = "";
    bool solve(string& curr, vector<int>& count, string& target, int i,
               bool greater) {
        if (i == target.length()) {
            if (greater) {
                result = curr;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;
            if (greater == false && ch < target[i])
                continue;
            curr.push_back(ch);
            count[ch - 'a']--;
            bool isGreater = greater || ch > target[i];
            if (solve(curr, count, target, i + 1, isGreater)) {
                return true;
            }
            curr.pop_back();
            count[ch - 'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char& ch : s)
            count[ch - 'a']++;
        string curr;
        solve(curr, count, target, 0, false);

        return result;
    }
};
t.c. = o(n)
s.c. = o(n)
  
