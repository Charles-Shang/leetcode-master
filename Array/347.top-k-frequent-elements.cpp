/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (64.61%)
 * Likes:    12319
 * Dislikes: 455
 * Total Accepted:    1.3M
 * Total Submissions: 2M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */

// @lc code=start
class Solution {
   public:
    static bool sortbysec(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> bucket;

        for (int i = 0; i < nums.size(); i++) {
            if (bucket.count(nums[i])) {
                bucket[nums[i]]++;
            } else {
                bucket[nums[i]] = 1;
            }
        }

        vector<pair<int, int>> temp;

        for (map<int, int>::iterator iter = bucket.begin(); iter != bucket.end(); ++iter) {
            temp.push_back(make_pair(iter->first, iter->second));
        }

        sort(temp.begin(), temp.end(), sortbysec);

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};
// @lc code=end
