A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

 

Example 1:


Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.
Example 2:


Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is either '(' or ')'.

 //solution
 class Solution {
public:
    int dp[101][101][202];
    int solve(vector<vector<char>>& g, int i, int j, int op) {
        if (op < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 'c')
            return 0;
        if (i == g.size() - 1 && j == g[0].size() - 1) {
            if (g[i][j] == '(')
                return 0;
            return op == 1;
        }
        if (dp[i][j][op] != -1)
            return dp[i][j][op];

        int op1 = solve(g, i + 1, j, g[i][j] == '(' ? op + 1 : op - 1);
        if (op1)
            return dp[i][j][op + 1] = 1;
        int op2 = solve(g, i, j + 1, g[i][j] == '(' ? op + 1 : op - 1);
        if (op2)
            return dp[i][j][op] = 1;
        return dp[i][j][op] = op1 || op2;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0);
    }
};

t.c. = O(m×n×(m+n))
