class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, idx = -1, i = 0;
        while (n) {
            if (n & 1) {
                if (idx >= 0)
                    ans = max(ans, i - idx);
                idx = i;
            }
            n >>= 1;
            i++;
        }
        return ans;
    }
};
