Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.


  //solution
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool cycleDetectDFS(int r, int c, int prev_r, int prev_c, 
                    vector<vector<char>>& grid, vector<vector<bool>>& visited ) {

        if(visited[r][c]) {
            return true;
        }
        visited[r][c] = true;
        for(auto &dir : directions) {
            int new_r = r + dir[0]; 
            int new_c = c + dir[1];

            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[r][c]) {
                    if(new_r == prev_r && new_c == prev_c)
                        continue;
                    
                    if(cycleDetectDFS(new_r, new_c, r, c, grid, visited)) {
                        return true;
                    }
                }
        }

        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && cycleDetectDFS(i, j, i, j, grid, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

T.C. = O(N*M)
