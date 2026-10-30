You are given an array of positive integers nums and a positive integer k. You are also given a 2D array queries, where queries[i] = [indexi, valuei, starti, xi].

You are allowed to perform an operation once on nums, where you can remove any suffix from nums such that nums remains non-empty.

The x-value of nums for a given x is defined as the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x modulo k.

For each query in queries you need to determine the x-value of nums for xi after performing the following actions:

Update nums[indexi] to valuei. Only this step persists for the rest of the queries.
Remove the prefix nums[0..(starti - 1)] (where nums[0..(-1)] will be used to represent the empty prefix).
Return an array result of size queries.length where result[i] is the answer for the ith query.

A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

Note that the prefix and suffix to be chosen for the operation can be empty.

Note that x-value has a different definition in this version.

 

Example 1:

Input: nums = [1,2,3,4,5], k = 3, queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]

Output: [2,2,2]

Explanation:

For query 0, nums becomes [1, 2, 2, 4, 5], and the empty prefix must be removed. The possible operations are:
Remove the suffix [2, 4, 5]. nums becomes [1, 2].
Remove the empty suffix. nums becomes [1, 2, 2, 4, 5] with a product 80, which gives remainder 2 when divided by 3.
For query 1, nums becomes [1, 2, 2, 3, 5], and the prefix [1, 2, 2] must be removed. The possible operations are:
Remove the empty suffix. nums becomes [3, 5].
Remove the suffix [5]. nums becomes [3].
For query 2, nums becomes [1, 2, 2, 3, 5], and the empty prefix must be removed. The possible operations are:
Remove the suffix [2, 2, 3, 5]. nums becomes [1].
Remove the suffix [3, 5]. nums becomes [1, 2, 2].
Example 2:

Input: nums = [1,2,4,8,16,32], k = 4, queries = [[0,2,0,2],[0,2,0,1]]

Output: [1,0]

Explanation:

For query 0, nums becomes [2, 2, 4, 8, 16, 32]. The only possible operation is:
Remove the suffix [2, 4, 8, 16, 32].
For query 1, nums becomes [2, 2, 4, 8, 16, 32]. There is no possible way to perform the operation.
Example 3:

Input: nums = [1,1,2,1,1], k = 2, queries = [[2,1,0,1]]

Output: [5]

 

Constraints:

1 <= nums[i] <= 109
1 <= nums.length <= 105
1 <= k <= 5
1 <= queries.length <= 2 * 104
queries[i] == [indexi, valuei, starti, xi]
0 <= indexi <= nums.length - 1
1 <= valuei <= 109
0 <= starti <= nums.length - 1
0 <= xi <= k - 1


 //solution
 class SegmentTree {
public:

    struct Node {
        vector<int> pre=vector<int>(6,0);
        int mul = 1;
    };

    int n, k, size;
    vector<Node> tree;

    SegmentTree(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;

        size = 1;
        while (size < n)
            size *= 2;

        tree.resize(2 * size);

        build(nums);
    }

    Node merge(const Node& a, const Node& b) {
        Node res;

        for (int x = 0; x < k; x++)
            res.pre[x] = a.pre[x];

        for (int x = 0; x < k; x++)
            res.pre[(a.mul * x) % k] += b.pre[x];

        res.mul = (a.mul * b.mul) % k;

        return res;
    }

    void build(vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            int x = nums[i] % k;

            tree[size + i].pre[x] = 1;
            tree[size + i].mul = x;
        }

        for (int i = size - 1; i >= 1; i--)
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
    }

    void update(int pos, int val) {
        pos += size;

        tree[pos].pre.assign(6,0);

        int x = val % k;

        tree[pos].pre[x] = 1;
        tree[pos].mul = x;

        pos /= 2;

        while (pos) {
            tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
            pos /= 2;
        }
    }

    Node query(int l, int r) {
        l += size;
        r += size;

        Node left, right;

        while (l <= r) {
            if (l & 1)
                left = merge(left, tree[l++]);

            if (!(r & 1))
                right = merge(tree[r--], right);

            l /= 2;
            r /= 2;
        }

        return merge(left, right);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k,
                           vector <vector<int>>& queries) {

        SegmentTree seg(nums, k);

        vector<int> ans;

        for (auto &q : queries) {
            seg.update(q[0], q[1]);

            auto res = seg.query(q[2], nums.size() - 1);

            ans.push_back(res.pre[q[3]]);
        }

        return ans;
    }
};
