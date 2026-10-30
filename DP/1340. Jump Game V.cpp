Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and  0 < x <= d.
i - x where: i - x >= 0 and  0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

  Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 105
1 <= d <= arr.length

  //solution
class Solution {
public:
    int n;
    vector<int> t;
    int solve(vector<int>& arr, int d, int i) {
        if (t[i] != -1)
            return t[i];
        int result = 1; 
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

        return t[i] = result;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        t.resize(n, -1);
        int maxJump = 1;
        for (int i = 0; i < n; i++) {
            maxJump = max(maxJump, solve(arr, d, i));
        }
         return maxJump;
    }
};

Approach Recursion & memoization
T.C = O(n*d)
S.C = O(n)
