/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (60.76%)
 * Likes:    8874
 * Dislikes: 348
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head. You
 * must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 *
 *
 * Example 2:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur && cur->next) {
            if (pre) {
                ListNode* next = cur->next;
                ListNode* nextnext = next->next;
                pre->next = next;
                cur->next = nextnext;
                next->next = cur;
                pre = cur;
                cur = nextnext;
            } else {
                ListNode* next = cur->next;
                head = next;
                ListNode* nextnext = next->next;
                cur->next = nextnext;
                next->next = cur;
                pre = cur;
                cur = nextnext;
            }
        }

        return head;
    }
};
// @lc code=end
