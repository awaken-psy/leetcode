/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (49.18%)
 * Likes:    3112
 * Dislikes: 0
 * Total Accepted:    662K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> indices;
        vector<int> left(n), right(n);

        /*
        处理下标 i 时：

        1.如果栈顶高度 >= heights[i]，就不断弹出。
        2.弹出结束后：
            栈为空：左边不存在更矮的柱子，left[i] = -1。
            栈不为空：栈顶就是左边最近的更矮柱子，left[i] = stack.top()。
        3.把当前下标 i 入栈，供后面的柱子使用。
        */

        // 顺序，压栈从小到大
        for (int i = 0; i < n; i++) {
            while (!indices.empty() && heights[indices.top()] >= heights[i]) indices.pop();
            left[i] = indices.empty() ? -1 : indices.top();
            indices.push(i);
        }

        while (!indices.empty()) indices.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!indices.empty() && heights[indices.top()] >= heights[i]) indices.pop();
            right[i] = indices.empty() ? n : indices.top();
            indices.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            ans = max(ans, width * heights[i]);
        }

        return ans;
    }
};
// @lc code=end
