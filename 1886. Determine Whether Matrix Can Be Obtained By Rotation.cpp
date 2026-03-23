Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating 
mat in 90-degree increments, or false otherwise.


Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.

  //solution
  class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        // transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
            if(mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};
