You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with weight wi.

You are also given a string labels of length n, where labels[i] is the character assigned to node i, and an integer k.

Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along the path contains at most k consecutive identical characters. If no valid path exists, return -1.

 

Example 1:

Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1

Output: 3

Explanation:

The optimal valid path from node 0 to node 2 is as follows:

Use edges[2] = [0, 2, 3] to reach node 2 with a weight wi = 3.
The corresponding concatenation of labels is "ab", which satisfies at most k = 1 consecutive identical characters. Thus, the answer is 3.
Example 2:

Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 2

Output: 2

Explanation:

The optimal valid path from node 0 to node 2 is as follows:

Use edges[0] = [0, 1, 1] to reach node 1 with weight wi = 1.
Use edges[1] = [1, 2, 1] to reach node 2 with weight wi = 1.
The corresponding concatenation of labels is "aab", which satisfies at most k = 2 consecutive identical characters. Thus, the answer is 2.
Example 3:

Input: n = 3, edges = [[0,1,1],[1,2,1]], labels = "aaa", k = 2

Output: -1

Explanation:

There is no valid path from node 0 to node 2 that satisfies at most k = 2 consecutive identical characters. Thus, the answer is -1.

 

Constraints:

1 <= n == labels.length <= 5 * 104
0 <= edges.length <= 5 * 104
edges[i] == [ui, vi, wi]
0 <= ui, vi <= n - 1
ui != vi
1 <= wi <= 104
labels consists of lowercase English letters
1 <= k <= 50


 //solution
 class Solution {
public:
    typedef tuple<int, int, int>  T ; 
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<vector<int>>> adj;
        for (auto &edge : edges) {
            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }
        vector<vector<int>> result(n, vector<int>(k + 1, INT_MAX));
        priority_queue<T, vector<T>, greater<T>> pq;
        result[0][1] = 0 ;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [d, node, count] = pq.top();
            pq.pop();

            if (d > result[node][count]) 
                continue;
            if (node == n - 1) 
                return d;
            for (auto &vec : adj[node]) {
                int adjNode = vec[0];
                int wt = vec[1];
                int newCount = (labels[adjNode] == labels[node]) ? count + 1 : 1;
                if (newCount > k) 
                    continue;
                int newDist = d + wt;
                if (newDist < result[adjNode][newCount]) {
                    result[adjNode][newCount] = newDist;
                    pq.push({newDist, adjNode, newCount});
                }
            }
        }
        return -1;
    }
};
