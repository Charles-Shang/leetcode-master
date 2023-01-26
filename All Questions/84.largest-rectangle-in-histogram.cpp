/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (42.32%)
 * Likes:    13208
 * Dislikes: 185
 * Total Accepted:    628.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 *
 *
 * Example 1:
 *
 *
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10
 * units.
 *
 *
 * Example 2:
 *
 *
 * Input: heights = [2,4]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int dfs(const vector<int>& h, int l, int r) {
        if (l == r) return h[l];
        int m = (l + r) / 2;
        int res = dfs(h, l, m);
        res = max(res, dfs(h, m + 1, r));
        int li = m, ri = m, mh = h[m];
        for (int i = 1; i <= r - l + 1; i++) {
            if (ri > r || (li >= l && h[li] > h[ri]))
                mh = min(mh, h[li--]);
            else
                mh = min(mh, h[ri++]);
            res = max(res, i * mh);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        return dfs(heights, 0, heights.size() - 1);
    }
};
// @lc code=end
