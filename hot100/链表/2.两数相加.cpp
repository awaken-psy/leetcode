/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (46.67%)
 * Likes:    11897
 * Dislikes: 0
 * Total Accepted:    2.8M
 * Total Submissions: 6M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空
 * 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 *
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 *
 *
 * 示例 2：
 *
 *
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 *
 *
 * 示例 3：
 *
 *
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            tail->next = new ListNode(sum % 10);
            carry = sum / 10;
            tail = tail->next;
        }

        return dummy.next;
    }
};
// @lc code=end

/*
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // save the begin
        ListNode* head = l1;
        bool carry = false;
        while (1) {
            l1->val += l2->val + (int)carry;
            carry = (l1->val >= 10) ? true : false;
            l1->val %= 10;

            if (!l1->next || !l2->next) {
                break;
            }
            l1 = l1->next, l2 = l2->next;
        }

        // case1:l1 goes to end,l2 remains,l1's end point to l2 next
        // case2:l2 goes to end,l1 remains,do nothing
        // case3:both goes to end,do nothing
        if (!l1->next && l2->next) {
            l1->next = l2->next;
        }

        // until l1 point to the last node
        while (l1->next) {
            l1 = l1->next;
            l1->val += (int)carry;
            carry = (l1->val >= 10) ? true : false;
            l1->val %= 10;
        }

        // handle the final node
        if (carry) {
            l1->next = new ListNode(1);
        }

        return head;
    }
};
*/
