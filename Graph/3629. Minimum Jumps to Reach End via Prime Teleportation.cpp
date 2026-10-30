You are given an integer array nums of length n.

You start at index 0, and your goal is to reach index n - 1.

From any index i, you may perform one of the following operations:

Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
Return the minimum number of jumps required to reach index n - 1.

 

Example 1:

Input: nums = [1,2,4,6]

Output: 2

Explanation:

One optimal sequence of jumps is:

Start at index i = 0. Take an adjacent step to index 1.
At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.
Thus, the answer is 2.

Example 2:

Input: nums = [2,3,4,7,9]

Output: 2

Explanation:

One optimal sequence of jumps is:

Start at index i = 0. Take an adjacent step to index i = 1.
At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to index i = 4 since nums[4] = 9 is divisible by 3.
Thus, the answer is 2.

Example 3:

Input: nums = [4,6,5,8]

Output: 3

Explanation:

Since no teleportation is possible, we move through 0 → 1 → 2 → 3. Thus, the answer is 3.
 

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= 106

//solution

class Solution {
public:
    vector<bool> isPrime;
    
    void buildSieve(int maxEl) {
        //fill isPrime
        isPrime.resize(maxEl+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num*num <= maxEl; num++) {
            if(isPrime[num]) {

                for(int multiple = num*num; multiple <= maxEl; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; 
        int maxEl = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }
        buildSieve(maxEl); 

        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                int i = que.front();
                que.pop();

                if(i == n-1) {
                    return steps;
                }

                if(i-1 >= 0 && !visited[i-1]) {
                    que.push(i-1);
                    visited[i-1] = true;
                }

                if(i+1 <= n-1 && !visited[i+1]) {
                    que.push(i+1);
                    visited[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]) {
                    if(!mp.contains(multiple)) {
                        continue;
                    }

                    for(int &j : mp[multiple]) {
                        if(!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }
                seen.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};
Approach  BFS + Sieve
T.C : O(maxEL * loglog(maxEl))
S.C : O(maxEl + n)
