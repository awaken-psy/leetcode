/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (79.07%)
 * Likes:    4063
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.6M
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：["()"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
 *
 *
 */

// @lc code=start
class Solution {
   private:
    int valid = 0;  // 加入一个左括号则++，加入一个右括号则--，必须>=0
    int l = 0;      // 已加入的左括号数，必须满足<=n
    vector<string> solution;
    string answer;
    void traceback(int n) {
        if (answer.length() == 2 * n) {
            solution.push_back(answer);
            return;
        }
        if (l < n) {
            answer.push_back('(');
            l++, valid++;
            traceback(n);
            answer.pop_back();
            l--, valid--;
        }
        if (valid > 0) {
            answer.push_back(')');
            valid--;
            traceback(n);
            answer.pop_back();
            valid++;
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        traceback(n);
        return solution;
    }
};
// @lc code=end
