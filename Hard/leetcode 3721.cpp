You are given an integer array nums.

A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

Return the length of the longest balanced subarray.

 

Example 1:

Input: nums = [2,5,4,3]

Output: 4

Explanation:

The longest balanced subarray is [2, 5, 4, 3].
It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
Example 2:

Input: nums = [3,2,2,5,4]

Output: 5

Explanation:

The longest balanced subarray is [3, 2, 2, 5, 4].
It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.
Example 3:

Input: nums = [1,2,3,2]

Output: 3

Explanation:

The longest balanced subarray is [2, 3, 2].
It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105












class Solution {
public:

    struct ST {
        vector<int> mn,mx,lz;
        ST(int n){ mn=mx=lz=vector<int>(4*n); }

        void push(int i,int l,int r){
            if(!lz[i]) return;
            mn[i]+=lz[i]; mx[i]+=lz[i];
            if(l!=r) lz[i*2]+=lz[i], lz[i*2+1]+=lz[i];
            lz[i]=0;
        }

        void upd(int i,int l,int r,int ql,int qr,int v){
            push(i,l,r);
            if(r<ql||l>qr) return;
            if(ql<=l&&r<=qr){ lz[i]+=v; push(i,l,r); return; }
            int m=(l+r)/2;
            upd(i*2,l,m,ql,qr,v);
            upd(i*2+1,m+1,r,ql,qr,v);
            mn[i]=min(mn[i*2],mn[i*2+1]);
            mx[i]=max(mx[i*2],mx[i*2+1]);
        }

        int find0(int i,int l,int r){
            push(i,l,r);
            if(mn[i]>0||mx[i]<0) return -1;
            if(l==r) return l;
            int m=(l+r)/2;
            int x=find0(i*2,l,m);
            return x!=-1?x:find0(i*2+1,m+1,r);
        }
    };

    int longestBalanced(vector<int>& a) {

        int n=a.size(),ans=0;
        ST st(n);
        unordered_map<int,int> last;

        for(int r=0;r<n;r++){
            int val=(a[r]%2==0)?1:-1;
            st.upd(1,0,n-1,0,r,val);
            if(last.count(a[r]))
                st.upd(1,0,n-1,0,last[a[r]],-val);
            last[a[r]]=r;

            int l=st.find0(1,0,n-1);
            if(l!=-1) ans=max(ans,r-l+1);
        }
        return ans;
    }
};
