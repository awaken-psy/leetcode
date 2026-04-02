/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (63.48%)
 * Likes:    3112
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        // 用队列模拟"镜像对比"，每次入队都成对入队（左镜像位, 右镜像位）
        queue<TreeNode*> q;
        q.push(root->left);   // 根的左子树
        q.push(root->right);  // 根的右子树（与左互为镜像）

        while (!q.empty()) {
            // 每次取出一对节点，判断它们是否"镜像相等"
            TreeNode* L = q.front(); q.pop();
            TreeNode* R = q.front(); q.pop();

            if (!L && !R) continue;             // 两个都是空，这对镜像合法，继续
            if (!L || !R) return false;         // 一个空一个非空，不对称
            if (L->val != R->val) return false; // 值不同，不对称

            // 将下一层的镜像对入队
            // 外侧：L的左孩子 对应 R的右孩子
            q.push(L->left);
            q.push(R->right);
            // 内侧：L的右孩子 对应 R的左孩子
            q.push(L->right);
            q.push(R->left);
        }
        return true; // 所有镜像对都通过检查
    }
};
// @lc code=end
