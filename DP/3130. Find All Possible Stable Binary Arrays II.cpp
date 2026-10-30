You are given 3 positive integers zero, one, and limit.

A binary array arr is called stable if:

The number of occurrences of 0 in arr is exactly zero.
The number of occurrences of 1 in arr is exactly one.
Each subarray of arr with a size greater than limit must contain both 0 and 1.
Return the total number of stable binary arrays.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: zero = 1, one = 1, limit = 2

Output: 2

Explanation:

The two possible stable binary arrays are [1,0] and [0,1].

Example 2:

Input: zero = 1, one = 2, limit = 1

Output: 1

Explanation:

The only possible stable binary array is [1,0,1].

Example 3:

Input: zero = 3, one = 3, limit = 2

Output: 14

Explanation:

All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].

 

Constraints:

1 <= zero, one, limit <= 1000



 //solution
 typedef long long ll;
class Solution {
public:
    const ll mod = 1e9+7;
    ll dp[1001][1001][2];
    ll f(ll a, ll b, ll last, ll k)
    {
        if(a<0 || b<0) return 0;
        if(a==0 && b==0) return 0;
        if(a==0 || b==0){
            if(a==0){
                return last==1 && b<=k;
            }
            else
            {
                return last==0 && a<=k;
            }
        }
        if(dp[a][b][last]!=-1) return dp[a][b][last];
        if(last == 0){
            return dp[a][b][last] = ((f(a-1,b,0,k) + f(a-1,b,1,k))%mod - (f(a-k-1,b,1,k)%mod) + mod)%mod;
        }
        else{
            return dp[a][b][last] = ((f(a,b-1,1,k)+f(a,b-1,0,k))%mod-(f(a,b-k-1,0,k)%mod) + mod)%mod;
        }
    }
    int numberOfStableArrays(int zero, int one, int k) {
        memset(dp,-1,sizeof(dp));
        return (f(zero,one,0,k)+f(zero,one,1,k))%mod;
    }
};
