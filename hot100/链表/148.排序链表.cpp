/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (67.68%)
 * Likes:    2739
 * Dislikes: 0
 * Total Accepted:    902.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
    ListNode* getmid(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortmerge(ListNode* left, ListNode* right) {
        ListNode dummy(0, nullptr);
        ListNode* l = &dummy;
        while (left && right) {
            if (left->val > right->val) {
                l->next = right;
                l = l->next;
                right = right->next;
            } else {
                l->next = left;
                l = l->next;
                left = left->next;
            }
        }
        if (left == nullptr) {
            l->next = right;
        } else {
            l->next = left;
        }
        return dummy.next;
    }

   public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* mid = getmid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        // cut down the link
        mid->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return sortmerge(left, right);
    }
};
// @lc code=end
