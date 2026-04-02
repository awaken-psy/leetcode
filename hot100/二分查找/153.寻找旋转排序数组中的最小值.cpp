/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (59.11%)
 * Likes:    1351
 * Dislikes: 0
 * Total Accepted:    800.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组
 * nums = [0,1,2,4,5,6,7] 在变化后可能得到：
 *
 * 若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
 * 若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
 *
 *
 * 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2],
 * ..., a[n-2]] 。
 *
 * 给你一个元素值 互不相同 的数组 nums
 * ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
 *
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,4,5,1,2]
 * 输出：1
 * 解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [4,5,6,7,0,1,2]
 * 输出：0
 * 解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [11,13,15,17]
 * 输出：11
 * 解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * nums 中的所有整数 互不相同
 * nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int minnum = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            //   nums[mid] > nums[right] → 左侧有序，最小值在右边
            //   nums[mid] <= nums[right] → 右侧有序，最小值在左边（含 mid）
            // 必须与 nums[right] 比而非 nums[left]：
            //   mid 向下取整，区间剩2个元素时 left==mid，nums[left]和nums[mid]是同一元素，比了没信息
            //   而 right>mid 在区间>1时恒成立，nums[right]和nums[mid]必然不同，比较有意义
            //  mid的计算方式决定了天然向左偏
            bool isleftorder = nums[right] < nums[mid];

            if (isleftorder) {
                minnum = min(nums[left], minnum);
                left = mid + 1;
            } else {
                minnum = min(nums[mid], minnum);
                right = mid - 1;
            }
        }
        return minnum;
    }
};
// @lc code=end
