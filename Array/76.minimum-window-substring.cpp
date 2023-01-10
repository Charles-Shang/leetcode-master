/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (40.77%)
 * Likes:    14017
 * Dislikes: 607
 * Total Accepted:    952K
 * Total Submissions: 2.3M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 *
 */

// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        map<char, int> sMap, tMap;
        for (auto c : t) tMap[c]++;
        string ans = "";
        int cnt = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            sMap[s[right]]++;
            if (sMap[s[right]] <= tMap[s[right]]) {
                cnt++;
            }

            while (sMap[s[left]] > tMap[s[left]]) {
                sMap[s[left++]]--;
            }

            if (cnt == t.size() && (ans.empty() || right - left + 1 < ans.size())) {
                ans = s.substr(left, right - left + 1);
            }

            right++;
        }
        return ans;
    }
};
// @lc code=end
