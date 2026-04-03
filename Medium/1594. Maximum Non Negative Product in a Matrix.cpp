You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

Notice that the modulo is performed after getting the maximum product.



  //solution
  class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const long long mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<long long> maxProd(n), minProd(n);
        maxProd[0] = minProd[0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                long long curr = grid[i][j];
                if (i == 0) {
                    maxProd[j] = minProd[j] = maxProd[j-1] * curr;
                } else if (j == 0) {
                    maxProd[j] = minProd[j] = maxProd[j] * curr;
                } else {
                    long long mx = max(maxProd[j-1], maxProd[j]);
                    long long mn = min(minProd[j-1], minProd[j]);
                    
                    if (curr >= 0) {
                        maxProd[j] = mx * curr;
                        minProd[j] = mn * curr;
                    } else {
                        maxProd[j] = mn * curr;
                        minProd[j] = mx * curr;
                    }
                }
            }
        }
        return maxProd[n-1] < 0 ? -1 : maxProd[n-1] % mod;
    }
};


Time comp = O(mn)
Space comp = O(n)

