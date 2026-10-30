Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.

//solution
 class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majority = -1;
        for(int i =0; i < n; i++){
            if(count == 0){
                majority = nums[i];
            }
            if(nums[i] == majority){
                count += 1;
            }else{
                count -= 1;
            }
        }
        return majority;
    }
};


class Solution{
    public :
    int majorityElement(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};
