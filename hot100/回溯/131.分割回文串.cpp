/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (75.15%)
 * Likes:    2195
 * Dislikes: 0
 * Total Accepted:    763.4K
 * Total Submissions: 1M
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 16
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
   private:
    vector<vector<string>> solution;
    vector<string> answer;
    void traceback(string& s, int start) {
        if (start == s.size()) {
            solution.push_back(answer);
            return;
        }
        for (int i = start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                answer.push_back(s.substr(start, i - start + 1));
                traceback(s, i + 1);
                answer.pop_back();
            }
        } }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

   public:
    vector<vector<string>> partition(string s) {
        traceback(s, 0);
        return solution;
    }
};
// @lc code=end
