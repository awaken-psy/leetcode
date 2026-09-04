/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (44.46%)
 * Likes:    7929
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3.3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的
 * 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // nums1必须是短数组，否则nums2会越界
        if (n2 < n1) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0, right = n1;
        int half = (n1 + n2 + 1) / 2;

        while (left <= right) {
            int mid1 = left + (right - left) / 2;
            int mid2 = half - mid1;

            int Aleft = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int Aright = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int Bleft = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int Bright = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if (Aleft > Bright) {
                right = mid1 - 1;
            } else if (Bleft > Aright) {
                left = mid1 + 1;
            } else {
                int leftmax = max(Aleft, Bleft);
                if ((n1 + n2) % 2 == 1) {
                    return leftmax;
                }
                int rightmin = min(Aright, Bright);
                return (double)(leftmax + rightmin) / 2;
            }
        }
        return -1;
    }
};
// @lc code=end
