You are given an integer array nums of length n.

An integer k is called sortable if k divides n and you can sort nums in non-decreasing order by sequentially performing the following operations:

Partition nums into consecutive subarrays of length k.
Cyclically rotate each subarray independently any number of times to the left or to the right.
Return an integer denoting the sum of all possible sortable integers k.

 

Example 1:

Input: nums = [3,1,2]

Output: 3

Explanation:​​​​​​​

For n = 3, possible divisors are 1 and 3.
For k = 1: each subarray has one element. No rotation can sort the array.
For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
Only k = 3 is sortable. Hence, the answer is 3.
Example 2:

Input: nums = [7,6,5]

Output: 0

Explanation:

For n = 3, possible divisors are 1 and 3.
For k = 1: each subarray has one element. No rotation can sort the array.
For k = 3: the single subarray [7, 6, 5] cannot be rotated into non-decreasing order.
No k is sortable. Hence, the answer is 0.
Example 3:

Input: nums = [5,8]

Output: 3

Explanation:​​​​​​​

For n = 2, possible divisors are 1 and 2.
Since [5, 8] is already sorted, every divisor is sortable. Hence, the answer is 1 + 2 = 3.
 

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= 105


 //solution
 class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    bool search(vector<int>& pat, vector<int>& txt) {
        int N = txt.size();
        int M = pat.size();
        vector<int> lps(M, 0);
        computeLPS(pat, lps);
        int i = 0; 
        int j = 0; 
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == M) {
                return true; 
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    bool isRotation(vector<int>& vec1, vector<int>& vec2) {
        vector<int> txt = vec2;
        txt.insert(end(txt), begin(vec2), end(vec2)); 
        return search(vec1, txt);
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));
        int result = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool valid = true;
            for (int start = 0; start < n; start += k) {
                vector<int> vec1(begin(nums) + start, begin(nums) + start + k);
                vector<int> vec2(begin(sorted) + start, begin(sorted) + start + k);
                if (!isRotation(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                result += k;
        }
        return result;
    }
};
