You are given two strings s and target, each of length n, consisting of lowercase English letters.

Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such permutation exists, return an empty string.

 

Example 1:

Input: s = "baba", target = "abba"

Output: "baab"

Explanation:

The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
The lexicographically smallest permutation that is strictly greater than target is "baab".
Example 2:

Input: s = "baba", target = "bbaa"

Output: ""

Explanation:

The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
None of them is lexicographically strictly greater than target. Therefore, the answer is "".
Example 3:

Input: s = "abc", target = "abb"

Output: ""

Explanation:

s has no palindromic permutations. Therefore, the answer is "".

Example 4:

Input: s = "aac", target = "abb"

Output: "aca"

Explanation:

The only palindromic permutation of s is "aca".
"aca" is strictly greater than target. Therefore, the answer is "aca".
 

Constraints:

1 <= n == s.length == target.length <= 300
s and target consist of only lowercase English letters.
 



  //solution
class Solution {
public:
    string ans;
    bool func(vector<char>& path,vector<int>& cnt,string & target, bool big,char mid,int n){
        if(!ans.empty()) return true;
        int half=n/2;
        if(path.size()==half){
            string left(path.begin(),path.end());
            string right=left;
            reverse(right.begin(),right.end());
            string pal="";
            if(n%2!=0)pal=left+mid+right;
            else pal=left+right;
            if(pal>target){
                ans=pal;
                return true;
            }
            return false;
        }
        int i=path.size();
        for(int c=0;c<26;c++){
            if(cnt[c]==0)continue;
            if(!big && c+'a'<target[i])continue;

            path.push_back(c+'a');
            cnt[c]--;
            bool newbig=big || (c+'a' >target[i]);
            if(func(path,cnt,target,newbig,mid,n))return true;
            path.pop_back();
            cnt[c]++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26,0);
        for(char c:s)cnt[c-'a']++;
        ans="";
        int odd=0;
        char mid=0;
        for(int i=0;i<26;i++){
            if(cnt[i]%2){
                odd++;
                mid='a'+i;   
            }
            cnt[i]/=2;
        }
        if(odd>1)return "";
        vector<char> path;
        func(path,cnt,target,false,mid,s.size());
        return ans;
    }
};

t.c. = o(n^2)
