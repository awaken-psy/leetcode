/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (45.66%)
 * Likes:    3018
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。
 *
 * 每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意
 * (i + j) 处：
 *
 *
 * 0 <= j <= nums[i] 且
 * i + j < n
 *
 *
 * 返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 题目保证可以到达 n - 1
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxreach = 0;  // 当前遍历过的所有位置中，能跳到的最远下标
        int end = 0;       // 本轮跳跃的边界：到达 end 时这一跳用完，必须再跳一次
        int count = 0;     // 跳跃次数

        // 只遍历到 n-2：最后一个位置不需要再起跳
        for (int i = 0; i < n - 1; i++) {
            // 用当前位置更新全局最远可达距离
            maxreach = max(maxreach, i + nums[i]);

            // 走到本轮边界，说明这一跳的"燃料"用完了，必须再跳一次
            // 把下一跳的边界设为目前见过的最远处
            if (i == end) {
                end = maxreach;
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
