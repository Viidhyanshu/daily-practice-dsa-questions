Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.


m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100

//solution

class Solution {
  public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
    int n = grid.size();
    int m = grid[0].size();
    while(k--){
      for(int i = 0; i < n; i++){
        for(int j = m-1; j > 0; j--){
          swap(grid[i][j], grid[i][j-1]);
        }
      }
      for(int i = n-1; i > 0; i++){
          swap(grid[i][0], grid[i-1][0]);
      }
    }
    return grid;
  }
};


t.c. = o(k*m*n)
