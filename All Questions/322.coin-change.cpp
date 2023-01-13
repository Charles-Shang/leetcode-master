/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (41.72%)
 * Likes:    15008
 * Dislikes: 349
 * Total Accepted:    1.3M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 *
 * Example 1:
 *
 *
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Example 3:
 *
 *
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount+ 1);
        mem[0] = 0;

        for (int i = 1; i <= amount; i++) {
            mem[i] = amount + 1;
            for (int coin : coins) {
                if (i - coin >= 0) {
                    mem[i] = min(mem[i], 1 + mem[i - coin]);
                }
            }
        }

        return mem[amount] != amount + 1 ? mem[amount] : -1;
    }
};
// @lc code=end
