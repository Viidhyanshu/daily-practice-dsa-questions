You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

There are no special characters in word.

Example 3:

Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in word.

 

Constraints:

1 <= word.length <= 2 * 105
word consists of only lowercase and uppercase English letters.



  //solution
class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lastSmall(26, -1);
        vector<int> firstCapital(26, -1);

        for(int i = 0; i < word.length(); i++) {
            
            char ch = word[i];

            if(islower(ch)) {
                lastSmall[ch - 'a'] = i;
            }
            else {
                if(firstCapital[ch - 'A'] == -1) {
                    firstCapital[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {

            if(lastSmall[i] != -1 && firstCapital[i] != -1 &&
               lastSmall[i] < firstCapital[i]) {
                count++;
            }
        }

        return count;
    }
};

 Approach = find last occurrence of lowercase and first occurrence of uppercase
T.C = O(n)
