You are given a string s consisting of lowercase English letters.

In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.

Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.

 

Example 1:

Input: s = "dog"

Output: 1

Explanation:​​​​​​​

Sort substring "og" to "go".
Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.
Example 2:

Input: s = "card"

Output: 2

Explanation:

Sort substring "car" to "acr", so s = "acrd".
Sort substring "rd" to "dr", making s = "acdr", which is sorted in ascending order. Thus, the answer is 2.
Example 3:

Input: s = "gf"

Output: -1

Explanation:

It is impossible to sort s under the given constraints. Thus, the answer is -1.
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.


//solution
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(begin(s), end(s)))
            return 0;
        if(n == 2) {
            return -1;
        }
        char min_char = *min_element(begin(s), end(s));
        char max_char = *max_element(begin(s), end(s));
        if(s[0] == min_char || s[n-1] == max_char)
            return 1;

        char max_mid = *max_element(begin(s)+1, end(s)-1);
        char min_mid = *min_element(begin(s)+1, end(s)-1);
        if(s[0] > max_mid && s[n-1] < min_mid) {
            return 3;
        }
        return 2;
    }
};
