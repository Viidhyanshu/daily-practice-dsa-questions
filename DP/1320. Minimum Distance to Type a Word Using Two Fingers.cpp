You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.

For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
Given the string word, return the minimum total distance to type such string using only two fingers.

The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

 

Example 1:

Input: word = "CAKE"
Output: 3
Explanation: Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -> cost = 0 
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -> cost = 0 
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3
Example 2:

Input: word = "HAPPY"
Output: 6
Explanation: Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
 

Constraints:

2 <= word.length <= 300
word consists of uppercase English letters.


  //solution

 Approach- Recursion and Memo with 5-D Memoization DP

class Solution {
public:
    int dp[301][7][7][7][7];
    pair<int, int> getCoordinate(char ch) {
        int pos = ch - 'A';
        return {pos / 6, pos % 6};
    }
    int getDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int solve(string &word, int i, int x1, int y1, int x2, int y2) {
        if (i == word.size()) 
            return 0;
        if (dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] != -1)
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1];
        auto [x, y] = getCoordinate(word[i]);
        if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {         //first finger not used
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = solve(word, i + 1, x, y, x2, y2); 
        }
        if (x2 == -1 && y2 == -1) {                  //second finger not used
            int moveF2 = solve(word, i + 1, x1, y1, x, y);

            int moveF1 = solve(word, i + 1, x, y, x2, y2) 
                             + getDistance(x1, y1, x, y);
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);
        }
        int moveF1 = solve(word, i + 1, x, y, x2, y2)       //both fingers used
                     + getDistance(x1, y1, x, y);
        int moveF2 = solve(word, i + 1, x1, y1, x, y) 
                     + getDistance(x2, y2, x, y);
        return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, -1, -1, -1, -1);
    }
};
T.C. = O(n*27*27) ~= O(n)
S.C. = O(n*27*27) ~= O(n)
