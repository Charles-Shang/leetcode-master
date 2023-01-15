/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (32.09%)
 * Likes:    5307
 * Dislikes: 4457
 * Total Accepted:    874.2K
 * Total Submissions: 2.7M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single
 * space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 *
 *
 *
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 *
 */

// @lc code=start
class Solution {
   public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        // remove all space
        int slow = 0, fast = 0;
        while (fast < s.size()) {
            if (s[fast] != ' ') {
                if (slow) {
                    s[slow] = ' ';
                    slow++;
                }
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }

            fast++;
        }

        s.resize(slow);

        // reverse entire stirng
        reverse(s, 0, s.size() - 1);

        // reverse words
        int left = 0, right = 0;
        while (right < s.size()) {
            if (s[right] == ' ') {
                reverse(s, left, right - 1);
                left = right + 1;
            }
            right++;
        }

        reverse(s, left, s.size() - 1);

        return s;
    }
};
// @lc code=end
