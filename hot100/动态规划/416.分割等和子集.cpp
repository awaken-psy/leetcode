/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (54.06%)
 * Likes:    2533
 * Dislikes: 0
 * Total Accepted:    975.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums
 * 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution {
   public:
    // 从数组中选出若干个数，使其和恰好等于 sum / 2
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2;

        // dp[j] 表示 目前考虑过的数字里，能凑出和为 j
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        // 顺序无关的dp
        // x = 2 -> 2
        // x = 5 -> 2 5 7
        // x = 4 -> 2 5 7 4 6 9 11
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            for (int j = target; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }

        return dp[target];
    }
};
// @lc code=end
