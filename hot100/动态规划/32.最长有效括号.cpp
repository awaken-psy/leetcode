/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (41.73%)
 * Likes:    2862
 * Dislikes: 0
 * Total Accepted:    717.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号 子串 的长度。
 *
 * 左右括号匹配，即每个左括号都有对应的右括号将其闭合的字符串是格式正确的，比如 "(()())"。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] 为 '(' 或 ')'
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n < 2) return 0;

        // dp[i] 表示以s[i]结尾的最长子串长度
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '(') continue;

            // ()结尾
            if (s[i - 1] == '(') {
                dp[i] += 2;
                if (i >= 2) {
                    dp[i] += dp[i - 2];
                }
            }
            // ))结尾
            else {
                int j = i - dp[i - 1] - 1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] += dp[i - 1] + 2;
                    if (j - 1 >= 0) {
                        dp[i] += dp[j - 1];
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end
