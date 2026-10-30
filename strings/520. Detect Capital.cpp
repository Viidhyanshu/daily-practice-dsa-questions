We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

  //solution
  
class Solution {
    public :
    bool detectCapitalUse(string word){
        int count = 0;
        for(int i = 0 ; i < word.length() ; i++){
            if(isupper(word[i])){
                count ++;
            }
        }
        return count == 0 || count == word.length() || (count == 1 && isupper(word[0]));
    }
};

t.c.  = O(n)
 s.c. = o(1)
