Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.


  //solution
  
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result =0 ;
        int m = mat.size();
        int n = mat[0].size();
        for(int row =0 ; row < m; row++){
            for(int col = 0; col < n; col++){
                if(mat[row][col]==0) {
                    continue;
                }
                bool special = true;
                for(int r =0 ; r < m; r++){
                    if(r != row && mat[r][col]==1){
                        special = false;
                        break;
                    }
                }
                for(int c =0 ; c < n; c++){
                    if(c != col && mat[row][c]==1){
                        special = false;
                        break;
                    }
                }
                if(special)
                result++;

            }
        }
    return result;
    }
};
