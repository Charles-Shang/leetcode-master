/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (57.76%)
 * Likes:    3513
 * Dislikes: 392
 * Total Accepted:    672.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> rMap;
        map<char, int> mMap;

        for (int i = 0; i < ransomNote.size(); i++) {
            rMap[ransomNote[i]]++;
        }

        for (int i = 0; i < magazine.size(); i++) {
            mMap[magazine[i]]++;
        }

        for (auto iter = rMap.begin(); iter != rMap.end(); iter++) {
            if (mMap[iter->first] < iter->second) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
