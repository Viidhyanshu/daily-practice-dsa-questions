You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.

You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.

You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.

Return the maximum possible minimum Manhattan distance between the selected k points.

The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.

 

Example 1:

Input: side = 2, points = [[0,2],[2,0],[2,2],[0,0]], k = 4

Output: 2

Explanation:



Select all four points.

Example 2:

Input: side = 2, points = [[0,0],[1,2],[2,0],[2,2],[2,1]], k = 4

Output: 1

Explanation:



Select the points (0, 0), (2, 0), (2, 2), and (2, 1).

Example 3:

Input: side = 2, points = [[0,0],[0,1],[0,2],[1,2],[2,0],[2,2],[2,1]], k = 5

Output: 1

Explanation:



Select the points (0, 0), (0, 1), (0, 2), (1, 2), and (2, 2).

 

Constraints:

1 <= side <= 109
4 <= points.length <= min(4 * side, 15 * 103)
points[i] == [xi, yi]
The input is generated such that:
points[i] lies on the boundary of the square.
All points[i] are unique.
4 <= k <= min(25, points.length)




// solution
// Key Idea: Maximizing minimum distance via binary search on answer with linear validation on circular perimeter.
class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        for (auto& p : points) {
            int x = p[0], y = p[1];

            if (x == 0) arr.push_back(y);
            else if (y == side) arr.push_back(1LL * side + x);
            else if (x == side) arr.push_back(3LL * side - y);
            else arr.push_back(4LL * side - x);
        }

        sort(arr.begin(), arr.end());

        long long low = 1, high = 2LL * side;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isValid(arr, side, k, mid)) {
                ans = (int)mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    bool isValid(vector<long long>& arr, int side, int k, long long dist) {
        long long peri = 4LL * side;

        for (int i = 0; i < arr.size(); i++) {
            long long start = arr[i];
            long long end = start + peri - dist;

            for (int j = 0; j < k - 1; j++) {
                int next = lower(arr, start + dist);

                if (next >= arr.size() || arr[next] > end) {
                    start = -1;
                    break;
                }

                start = arr[next];
            }

            if (start >= 0) return true;
        }

        return false;
    }

    int lower(vector<long long>& arr, long long target) {
        int low = 0, high = arr.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
T.C. =O(nlogn+n⋅klog(side))
