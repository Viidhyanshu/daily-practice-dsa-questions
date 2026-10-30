You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

In case there is no path, return [0, 0].

 

Example 1:

Input: board = ["E23","2X2","12S"]
Output: [7,1]
Example 2:

Input: board = ["E12","1X1","21S"]
Output: [4,2]
Example 3:

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 

Constraints:

2 <= board.length == board[i].length <= 100
//solution
class Solution {

    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> t;
    int getIntFromChar(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }
    bool isValid(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }
    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E') 
            return {0, 1};  
        if (board[i][j] == 'X') 
            return {0, 0};  

        if (t[i][j] != make_pair(-1, -1))
            return t[i][j];
        int upScore = 0,   upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;
        char ch = board[i][j];
        if (isValid(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0)
                upScore += getIntFromChar(ch);
        }
        if (isValid(i, j - 1, board)) {                
            auto [score, paths] = solve(i, j - 1, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0)
                leftScore += getIntFromChar(ch);
        }
        if (isValid(i - 1, j - 1, board)) {             
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0)
                diagScore += getIntFromChar(ch);
        }

        int bestScore, bestPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                bestScore = upScore; bestPaths = upPaths;
            }
        } else {
            bestScore = upScore; bestPaths = upPaths;
            if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }

        t[i][j] = {bestScore, bestPaths % MOD};
        return t[i][j];
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        
        t.assign(n, vector<pair<int, int>>(n, {-1, -1}));

        auto result = solve(n - 1, n - 1, board);
        return {result.first, result.second};
    }
};



by recursion and memoization
t.c. = O(n^2)
