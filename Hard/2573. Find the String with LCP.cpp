We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:

lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].
Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.

 

Example 1:

Input: lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
Output: "abab"
Explanation: lcp corresponds to any 4 letter string with two alternating letters. The lexicographically smallest of them is "abab".
Example 2:

Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
Output: "aaaa"
Explanation: lcp corresponds to any 4 letter string with a single distinct letter. The lexicographically smallest of them is "aaaa". 
Example 3:

Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
Output: ""
Explanation: lcp[3][3] cannot be equal to 3 since word[3,...,3] consists of only a single letter; Thus, no answer exists.
 

Constraints:

1 <= n == lcp.length == lcp[i].length <= 1000
0 <= lcp[i][j] <= n


  //solution
  

class Solution {
    vector<vector<int>> LongestCommonPrefixMatrix (string s) {
        int n = s.length();
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        for (int j = 0; j < n; j ++) {
            result[n-1][j] = result[j][n-1] = (s[j] == s[n-1])? 1 : 0; 
        }
        for (int i = n-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                result[i][j] = (s[i] == s[j])? 1 + result[i+1][j+1] : 0;
            }
        }
        
        return result;
    }
    
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        string result (n, 'a');
        
        for (int i = 1; i < n; i ++) {
            vector<bool> not_equal(26, false);
            bool matched = false;
            
            for (int j = 0; j < i; j ++) {
                if (lcp[j][i] == 0) {
                    not_equal[result[j] - 'a'] = true;
                    continue;
                }
                
                matched = true;
                result[i] = result[j];
                break;
            }
        
            if (matched) continue;
            for (int j = 0; j < 26; j ++) {
                if (not_equal[j]) continue;
                
                result[i] = (char)('a' + j);
                break;
            }
        }
        
        if (LongestCommonPrefixMatrix(result) == lcp) return result;
        return "";
    }
};
//Greedy Allocation + Finding LCP and comparing
//TC O(n^2)
//SC O(n^2)




//method 2
class Solution {
public:
    static string findTheString(vector<vector<int>>& lcp) {
        const int n = lcp.size();
        string s(n, 'a' - 1);
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a')
                continue;
            if (++id > 26)
                return "";
            for (int j = 0; j < n; j++)
                if (lcp[i][j])
                    s[j] = 'a' + id - 1;
        }
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i)
                return "";
            for (int j = i + 1; j < n; j++) {
                const int x = lcp[i][j];
                if (x != lcp[j][i])
                    return "";
                int y = (i < n - 1 && j < n - 1) ? lcp[i + 1][j + 1] : 0;
                y = (s[i] == s[j]) ? y + 1 : 0;
                if (x != y)
                    return "";
            }
        }
        return s;
    }
};
