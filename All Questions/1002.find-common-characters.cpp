/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.38%)
 * Likes:    2818
 * Dislikes: 231
 * Total Accepted:    168K
 * Total Submissions: 245.7K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given a string array words, return an array of all characters that show up
 * in all strings within the words (including duplicates). You may return the
 * answer in any order.
 *
 *
 * Example 1:
 * Input: words = ["bella","label","roller"]
 * Output: ["e","l","l"]
 * Example 2:
 * Input: words = ["cool","lock","cook"]
 * Output: ["c","o"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
   public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> ansInt(26, 0);
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (i == 0) {
                for (int j = 0; j < words[i].size(); j++) {
                    ansInt[words[i][j] - 'a']++;
                }
            } else {
                vector<int> temp(26, 0);
                for (int j = 0; j < words[i].size(); j++) {
                    temp[words[i][j] - 'a']++;
                }

                for (int j = 0; j < 26; j++) {
                    ansInt[j] = min(ansInt[j], temp[j]);
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < ansInt[i]; j++) {
                string s(1, i + 'a');
                ans.push_back(s);
            }
        }

        return ans;
    }
};
// @lc code=end
