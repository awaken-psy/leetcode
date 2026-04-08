/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (77.99%)
 * Likes:    1358
 * Dislikes: 0
 * Total Accepted:    838.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 *
 * 示例 2:
 *
 *
 * 输入: numRows = 1
 * 输出: [[1]]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= numRows <= 30
 *
 *
 */

// @lc code=start
class Solution {
   private:
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        for (int i = 0; i < numRows; i++) {
            dp.push_back(vector<int>{});
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    dp[i].push_back(1);
                else
                    dp[i].push_back(dp[i - 1][j] + dp[i - 1][j - 1]);
            }
        }
        return dp;
    }
};
// @lc code=end
