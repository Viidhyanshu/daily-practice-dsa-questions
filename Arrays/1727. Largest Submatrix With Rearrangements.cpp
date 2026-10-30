
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.




//solution

  class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix(m, vector<int> (n, 0));

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i == 0){
                    if(matrix[i][j] == 1)
                        prefix[i][j] = 1;
                }
                else{
                    if(matrix[i][j] == 1)
                        prefix[i][j] = prefix[i-1][j] + 1;
                    else
                        prefix[i][j] = 0;    
                }    
            }
        }
        
        int maxi = 0;
        for(int i=0 ; i<m ; i++){
            vector<int> temp;
            for(int j=0 ; j<n ; j++){
                if(prefix[i][j] != 0)
                    temp.push_back(prefix[i][j]);
            }

            sort(temp.begin(), temp.end());
            int k = temp.size();
            for(int i=0 ; i<k ; i++){
                maxi = max(maxi, temp[i] * (k-i));
            }
        }  
        return maxi; 
    }
};
