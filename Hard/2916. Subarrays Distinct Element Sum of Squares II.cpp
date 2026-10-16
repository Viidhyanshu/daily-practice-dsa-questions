You are given a 0-indexed integer array nums.

The distinct count of a subarray of nums is defined as:

Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
Return the sum of the squares of distinct counts of all subarrays of nums.

Since the answer may be very large, return it modulo 109 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
Example 2:

Input: nums = [2,2]
Output: 3
Explanation: Three possible subarrays are:
[2]: 1 distinct value
[2]: 1 distinct value
[2,2]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105

 //solution
 class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int n;
    vector<ll> sqSumSegTree;
    vector<ll> sumSegTree;
    vector<ll> lazyTree;
    void lazyAddition(int i, int l, int r, int val) {
        int len = (r-l+1);

        sqSumSegTree[i] += 2*val*sumSegTree[i] + len * val * val;
        sumSegTree[i] += (len * val);
    }
    void updateRange(int start, int end, int i, int l, int r, int val) {
        if(lazyTree[i] != 0) {
            lazyAddition(i, l, r, lazyTree[i]);

            if(l != r) {
                lazyTree[2*i+1] += lazyTree[i];
                lazyTree[2*i+2] += lazyTree[i];
            }
            lazyTree[i] = 0;
        }
        if(l > end || r < start || l > r) {
            return;
        }
        if(l >= start && r <= end) {
            lazyAddition(i, l, r, val);

            if(l != r) {
                lazyTree[2*i+1] += val;
                lazyTree[2*i+2] += val;
            }
            return;
        }
        int mid = l + (r-l)/2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);
        sumSegTree[i]   = sumSegTree[2*i+1] + sumSegTree[2*i+2];
        sqSumSegTree[i] = sqSumSegTree[2*i+1] + sqSumSegTree[2*i+2];
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sqSumSegTree.assign(4*n, 0);
        sumSegTree.assign(4*n, 0);
        lazyTree.assign(4*n, 0);
        vector<int> lastSeenIdx(100001, -1);
        ll result = 0;
        for(int i = 0; i < n; i++) {
            int start = lastSeenIdx[nums[i]] + 1;
            int end = i;
            updateRange(start, end, 0, 0, n-1, 1);
            result = (result + sqSumSegTree[0]) % MOD;
            lastSeenIdx[nums[i]] = i;
        }
        return result;
    }
};

