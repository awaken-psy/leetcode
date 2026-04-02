/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (76.19%)
 * Likes:    1990
 * Dislikes: 0
 * Total Accepted:    832.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
 *
 *
 * 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为
 * null 。 展开后的单链表应该与二叉树 先序遍历 顺序相同。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,5,3,4,null,6]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中结点数在范围 [0, 2000] 内
 * -100
 *
 *
 *
 *
 * 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 核心思路：先序遍历顺序是 根→左→右
// 对于每个节点，展开后的顺序应该是：cur → 左子树所有节点 → 右子树所有节点
//
// 关键操作：把右子树"搬到"左子树的末尾，再把左子树整体移到右边
// 这样 cur 的右边就变成了完整的先序序列，cur 自身处理完毕
// 然后 cur 向右走一步，对下一个节点重复同样操作
//
// 例：    1          第一轮后：    1
//        / \                       \
//       2   5         =>            2
//      / \   \                     / \
//     3   4   6                   3   4
//                                      \
//                                       5
//                                        \
//                                         6
// （之后 cur 移到 2，继续对 2 做同样处理，最终展开整个树）
class Solution {
   public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                // NOTE:右子树一定要接在左子树的根的右边
                // 因为每次操作都会使得左子树的根就位
                TreeNode* pre = cur->left;
                while (pre->right) pre = pre->right;

                // 第一步：把 cur 的右子树接到左子树最右节点的后面
                // 这样左子树的末尾就和原来的右子树连上了
                pre->right = cur->right;

                // 第二步：把左子树整体移到 cur 的右边
                cur->right = cur->left;
                cur->left = nullptr;
            }
            // cur 这一层处理完毕，向右走到下一个节点继续处理
            cur = cur->right;
        }
    }
};
// @lc code=end
