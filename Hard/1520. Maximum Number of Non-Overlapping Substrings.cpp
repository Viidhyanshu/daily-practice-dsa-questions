Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.

 

Example 1:

Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
Example 2:

Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.


 //solution
 class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<bool> isValid(26, true);
        vector<string> result;
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if(start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }
        for(int c = 0; c < 26; c++) { 
            if(start[c] == -1) continue;
       for(int i = start[c]; i <= end[c]; i++) {
                if(start[s[i]-'a'] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                end[c] = max(end[c], end[s[i]-'a']);
            }
        }
        int lastTakenStart = INT_MAX;
        for(int i = n-1; i >= 0; i--) {
            int c = s[i] - 'a';
            if(!isValid[c]) continue;
            if(i == start[c] && end[c] < lastTakenStart) {
                result.push_back(s.substr(i, end[c] - i + 1));
                lastTakenStart = i;
            }
        }
        return result;
    }
};

t.c. = o(n)
 s.c. = O(26)
 
