// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.80%)
 * Likes:    31190
 * Dislikes: 1357
 * Total Accepted:    4.1M
 * Total Submissions: 12.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;

        int max = 1;
        int left = 0, right = 0;
        while (right < s.length() - 1) {
            if (s.substr(left, right - left + 1).find(s[right + 1]) == string::npos) {
                right++;
                if (right - left + 1 > max) {
                    max = right - left + 1;
                }

            } else if (left == right) {
                right++;
                left++;
            } else {
                left++;
            }
        }

        return max;
    }
};
// @lc code=end
