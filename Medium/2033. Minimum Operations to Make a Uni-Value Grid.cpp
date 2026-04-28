You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.


  //solution
  
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vec;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vec.push_back(grid[i][j]);
            }
        }
        int L = vec.size(); 
        nth_element(begin(vec), begin(vec) + L/2, end(vec)); 

        int target = vec[L/2];
        int result = 0;
        for(int &num : vec) { 
            if(num%x != target%x) {
                return -1;
            }
            result += abs(target-num)/x;
        }
        return result;
    }
};

T.C. = O(M*N)

