/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (43.38%)
 * Likes:    4913
 * Dislikes: 10507
 * Total Accepted:    911.1K
 * Total Submissions: 2.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 *
 * Example 3:
 *
 *
 * Input: s = "A", numRows = 1
 * Output: "A"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 *
 *
 */

// @lc code=start
class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string result[numRows];
        int row = 0;
        bool down = false;
        for (int i = 0; i < s.size(); i++) {
            result[row].push_back(s[i]);

            if (row == 0) {
                down = true;
            } else if (row == numRows - 1) {
                down = false;
            }

            down ? row++ : row--;
        }

        string finStr = "";
        for (int i = 0; i < numRows; i++) {
            finStr += result[i];
        }

        return finStr;
    }
};
// @lc code=end
