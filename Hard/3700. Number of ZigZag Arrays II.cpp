You are given three integers n, l, and r.



A ZigZag array of length n is defined as follows:

Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.

A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

Example 1:

Input: n = 3, l = 4, r = 5

Output: 2

Explanation:

There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

[4, 5, 4]
[5, 4, 5]
Example 2:

Input: n = 3, l = 1, r = 3

Output: 10

Explanation:

​​​​​​​There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

[1, 2, 1], [1, 3, 1], [1, 3, 2]
[2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
[3, 1, 2], [3, 1, 3], [3, 2, 3]
All arrays meet the ZigZag conditions.

 

Constraints:

3 <= n <= 109
1 <= l < r <= 75
  
  
  //solution
  
  ​​​class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<vector<long long>> T(m, vector<long long>(m, 0));

        for (int j = 0; j < m; j++) {
            for (int i = m - j; i < m; i++) {
                T[i][j] = 1;
            }
        }

        auto powT = matPow(T, n - 1);

        long long total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                total = (total + powT[i][j]) % MOD;
            }
        }

        return static_cast<int>((total * 2) % MOD);
    }

private:
    vector<vector<long long>> matPow(vector<vector<long long>> base, long long exp) {
        int m = base.size();

        vector<vector<long long>> res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<vector<long long>> mul(const vector<vector<long long>>& A,
                                  const vector<vector<long long>>& B) {
        int m = A.size();

        vector<vector<long long>> C(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < m; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }
};

t.c. = o(m^3 logn)​​​​
