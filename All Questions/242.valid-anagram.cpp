/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (62.85%)
 * Likes:    7932
 * Dislikes: 253
 * Total Accepted:    1.9M
 * Total Submissions: 3M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

// @lc code=start
class Solution {
   public:
    bool isAnagram(string s, string t) {
        map<char, int> sMap;
        map<char, int> tMap;

        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            tMap[t[i]]++;
        }

        if (sMap.size() != tMap.size()) {
            return false;
        } else {
            for (auto iter = sMap.begin(); iter != sMap.end(); iter++) {
                if (tMap[iter->first] != iter->second) {
                    return false;
                }
            }

            return true;
        }
    }
};
// @lc code=end
