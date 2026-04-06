/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (49.07%)
 * Likes:    2825
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,0,1,2]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        // 将 nums 所有元素存入哈希集合，自动去重，后续查找 O(1)
        unordered_set<int> st(nums.begin(), nums.end());
        int maxlen = 0;

        for (int num : st) {
            // 只从序列的"起点"开始计数，跳过非起点避免重复计算
            // 例如序列 [1,2,3,4] 中，只有 1 的前驱 0 不在集合里，从 1 开始数
            // 2、3、4 都有前驱在集合里，跳过，否则会重复计算导致 O(n²)
            if (!st.count(num - 1)) {
                int len = 1;
                // 从起点往后探，看 num+1, num+2... 是否连续存在于集合中
                while (st.count(num + len)) {
                    len++;
                }
                // 更新最长长度
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};
// @lc code=end
