There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104



  //solution
  class Solution {
public:
    int findPivoit(vector<int>& nums, int n) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    int binarySearch(int l, int r, vector<int>& nums, int target) {
        int idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                idx = mid;
                break;
            } 
            else if (nums[mid] < target) {
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }
        return idx;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivoit_index = findPivoit(nums, n);
        int idx = binarySearch(0, pivoit_index - 1, nums, target);

        if (idx != -1)
            return idx;
        idx = binarySearch(pivoit_index, n - 1, nums, target);
        return idx;
    }
};
