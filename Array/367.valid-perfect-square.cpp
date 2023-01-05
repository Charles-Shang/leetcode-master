/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.29%)
 * Likes:    3154
 * Dislikes: 269
 * Total Accepted:    445.3K
 * Total Submissions: 1M
 * Testcase Example:  '16'
 *
 * Given a positive integer num, return true if num is a perfect square or
 * false otherwise.
 *
 * A perfect square is an integer that is the square of an integer. In other
 * words, it is the product of some integer with itself.
 *
 * You must not use any built-in library function, such as sqrt.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 16
 * Output: true
 * Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
 *
 *
 * Example 2:
 *
 *
 * Input: num = 14
 * Output: false
 * Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an
 * integer.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
   public:
    bool isPerfectSquare(int num) {

        if (num == 1) return true;

        int left = 0, right = num;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            if (num / pivot == pivot && num % pivot == 0) {
                return true;
            } else if (num / pivot == pivot) {
                return false;
            } else if (num / pivot > pivot) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }

        return false;
    }
};
// @lc code=end
