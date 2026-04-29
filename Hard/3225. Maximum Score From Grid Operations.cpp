You are given a 2D matrix grid of size n x n. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices (i, j), and color black all the cells of the jth column starting from the top row down to the ith row.

The grid score is the sum of all grid[i][j] such that cell (i, j) is white and it has a horizontally adjacent black cell.

Return the maximum score that can be achieved after some number of operations.

//solution
  
class Solution {
public:
    vector<vector<long long>> pref;
    vector<vector<int>> grid;
    int n;
    long long dp[2][105][105];
    long long helper(int prevTaken, int prevLen, int col) {
        if (col == n + 1) return 0;
        if (dp[prevTaken][prevLen][col] != -1)
            return dp[prevTaken][prevLen][col];
        long long ans = 0;
        for (int len = 0; len <= n; len++) {
            long long prevans = 0, currans = 0;
            if (prevTaken == 0 && col > 1 && len > prevLen) {
                prevans = pref[len][col - 1] - pref[prevLen][col - 1];
            }
            if (prevLen > len) {
                currans = pref[prevLen][col] - pref[len][col];
            }
            long long ans1 = currans + prevans + helper(1, len, col + 1);
            long long ans2 = prevans + helper(0, len, col + 1);
            ans = max(ans, max(ans1, ans2));
        }
        return dp[prevTaken][prevLen][col] = ans;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();

        pref.assign(n + 1, vector<long long>(n + 1, 0));
        memset(dp, -1, sizeof(dp));

        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= n; i++) {
                pref[i][j + 1] = pref[i - 1][j + 1] + grid[i - 1][j];
            }
        }
        return helper(0, 0, 1);
    }
};
