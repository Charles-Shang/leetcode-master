/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (45.41%)
 * Likes:    8509
 * Dislikes: 380
 * Total Accepted:    601.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 *
 *
 * Follow up: Could you do it in one pass?
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newList = new ListNode();
        ListNode* headptr = newList;

        ListNode* cur = head;
        for (int i = 0; i < left - 1; i++) {
            newList->next = cur;
            cur = cur->next;
            newList = newList->next;
            newList->next = nullptr;
        }

        ListNode* pre = nullptr;
        int counter = 0;
        while (cur && counter < right - left + 1)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            counter++;
        }

        newList->next = pre;
        for (int i = 0; i < right - left + 1; i++)
        {
            newList = newList->next;
        }
        
        newList->next = cur;
        
        return headptr->next;
    }
};
// @lc code=end
