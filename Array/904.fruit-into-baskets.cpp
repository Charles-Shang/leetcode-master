/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 *
 * https://leetcode.com/problems/fruit-into-baskets/description/
 *
 * algorithms
 * Medium (42.58%)
 * Likes:    1885
 * Dislikes: 135
 * Total Accepted:    251.7K
 * Total Submissions: 591.2K
 * Testcase Example:  '[1,2,1]'
 *
 * You are visiting a farm that has a single row of fruit trees arranged from
 * left to right. The trees are represented by an integer array fruits where
 * fruits[i] is the type of fruit the i^th tree produces.
 *
 * You want to collect as much fruit as possible. However, the owner has some
 * strict rules that you must follow:
 *
 *
 * You only have two baskets, and each basket can only hold a single type of
 * fruit. There is no limit on the amount of fruit each basket can hold.
 * Starting from any tree of your choice, you must pick exactly one fruit from
 * every tree (including the start tree) while moving to the right. The picked
 * fruits must fit in one of your baskets.
 * Once you reach a tree with fruit that cannot fit in your baskets, you must
 * stop.
 *
 *
 * Given the integer array fruits, return the maximum number of fruits you can
 * pick.
 *
 *
 * Example 1:
 *
 *
 * Input: fruits = [1,2,1]
 * Output: 3
 * Explanation: We can pick from all 3 trees.
 *
 *
 * Example 2:
 *
 *
 * Input: fruits = [0,1,2,2]
 * Output: 3
 * Explanation: We can pick from trees [1,2,2].
 * If we had started at the first tree, we would only pick from trees [0,1].
 *
 *
 * Example 3:
 *
 *
 * Input: fruits = [1,2,3,2,2]
 * Output: 4
 * Explanation: We can pick from trees [2,3,2,2].
 * If we had started at the first tree, we would only pick from trees
 * [1,2].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= fruits.length <= 10^5
 * 0 <= fruits[i] < fruits.length
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        map<int, int> basket;
        int maxfruits = 0;
        while (right < fruits.size()) {
            basket[fruits[right]]++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }

            maxfruits = max(maxfruits, right - left + 1);

            right++;
        }

        return maxfruits;
    }
};
// @lc code=end
