/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (41.65%)
 * Likes:    15248
 * Dislikes: 364
 * Total Accepted:    1.4M
 * Total Submissions: 3.4M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int getLeftBoundary(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int boundary = -1;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            if (nums[pivot] == target) {
                boundary = pivot;
                right = pivot - 1;
            } else if (nums[pivot] > target) {
                right = pivot - 1;
            } else {
                left = pivot + 1;
            }
        }

        return boundary;
    }

    int getRightBoundary(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int boundary = -1;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            if (nums[pivot] == target) {
                boundary = pivot;
                left = pivot + 1;
            } else if (nums[pivot] > target) {
                right = pivot - 1;
            } else {
                left = pivot + 1;
            }
        }

        return boundary;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = getLeftBoundary(nums, target), right = getRightBoundary(nums, target);
        return {left, right};
    }
};
// @lc code=end
