You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:

'S': Starting position of the student
'L': Litter that must be collected (once collected, the cell becomes empty)
'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
'X': Obstacle the student cannot pass through
'.': Empty space
You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.

Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.

Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.

 

Example 1:

Input: classroom = ["S.", "XL"], energy = 2

Output: 2

Explanation:

The student starts at cell (0, 0) with 2 units of energy.
Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
A valid sequence of moves to collect all litter is as follows:
Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
The student collects all the litter using 2 moves. Thus, the output is 2.
Example 2:

Input: classroom = ["LS", "RL"], energy = 4

Output: 3

Explanation:

The student starts at cell (0, 1) with 4 units of energy.
A valid sequence of moves to collect all litter is as follows:
Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining.
Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4.
Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
The student collects all the litter using 3 moves. Thus, the output is 3.
Example 3:

Input: classroom = ["L.S", "RXL"], energy = 3

Output: -1

Explanation:

No valid path collects all 'L'.

 

Constraints:

1 <= m == classroom.length <= 20
1 <= n == classroom[i].length <= 20
classroom[i][j] is one of 'S', 'L', 'R', 'X', or '.'
1 <= energy <= 50
There is exactly one 'S' in the grid.
There are at most 10 'L' cells in the grid.

 //solution
 class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    struct State {
            int row;
            int col;
            int energyLeft;
            int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;
        int startRow = 0;
        int startCol = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                litterBit[r][c] = -1;
                if (classroom[r][c] == 'S') {
                    startRow = r;
                    startCol = c;
                } else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;
        if (litterCount == 0) 
            return 0;

        VVVVB seen(m, VVVB(n, VVB(maxEnergy + 1, VB(1 << litterCount, false))));

        

        queue<State> que;
        que.push({startRow, startCol, maxEnergy, 0});
        seen[startRow][startCol][maxEnergy][0] = true;

        int moves = 0;

        while (!que.empty()) {
            int currSize = que.size();

            while (currSize--) {
                State current = que.front();
                que.pop();

                if (current.collectedMask == allCollected) 
                    return moves;
                if (current.energyLeft == 0) 
                    continue;

                for (auto& dir : directions) {
                    int nextRow = current.row + dir[0];
                    int nextCol = current.col + dir[1];

                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n) 
                        continue;

                    char cell = classroom[nextRow][nextCol];
                    if (cell == 'X') 
                        continue;

                    int nextEnergy = current.energyLeft - 1;
                    int nextMask   = current.collectedMask;

                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    } else if (cell == 'L') {
                        nextMask |= (1 << litterBit[nextRow][nextCol]);
                    }

                    if (!seen[nextRow][nextCol][nextEnergy][nextMask]) {
                        seen[nextRow][nextCol][nextEnergy][nextMask] = true;
                        que.push({nextRow, nextCol, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};

t.c. = O(m×n×energy×2^k)
