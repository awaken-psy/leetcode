/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode.cn/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (48.77%)
 * Likes:    2265
 * Dislikes: 0
 * Total Accepted:    603.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径
 * 的数目。
 *
 * 路径
 * 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * 输出：3
 * 解释：和等于 8 的路径有 3 条，如图所示。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：3
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,1000]
 * -10^9  
 * -1000  
 *
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
    // 必须以 node 为起点的路径中，有多少条和等于 target
    int countFrom(TreeNode* node, long target) {
        if (!node) return 0;
        return (node->val == target ? 1 : 0) + countFrom(node->left, target - node->val) +
               countFrom(node->right, target - node->val);
    }

    // 整棵子树中（起点任意）有多少条路径和等于 targetSum
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return countFrom(root, targetSum)          // 以 root 为起点
               + pathSum(root->left, targetSum)    // 起点在左子树
               + pathSum(root->right, targetSum);  // 起点在右子树
    }
};


/*
class Solution {
   public:
     导致会计入"跳过中间节点"的非法路径
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        int psum = pathSum(root->left, targetSum) + pathSum(root->right, targetSum) +
                   pathSum(root->left, targetSum - root->val) +
                   pathSum(root->right, targetSum - root->val) + (int)(root->val == targetSum);
        return psum;
    }
};
*/

// @lc code=end
