class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<long long> rowpre(n, 0), colpre(m, 0);
        rowpre[0] = accumulate(a[0].begin(), a[0].end(), 0LL);
        for(int i=0; i<n; i++) colpre[0] += a[i][0];
        for(int i=1; i<n; i++) rowpre[i] = rowpre[i-1] + accumulate(a[i].begin(), a[i].end(), 0LL);
        for(int i=1; i<m; i++) {
            colpre[i] = colpre[i-1];
            for(int j=0; j<n; j++) colpre[i] += a[j][i];
        }
        for(int i=0; i<n-1; i++) if(2*rowpre[i] == rowpre[n-1]) return true;
        for(int i=0; i<m-1; i++) if(2*colpre[i] == colpre[m-1]) return true;
        return false;
    }
};



