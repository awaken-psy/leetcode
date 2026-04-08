/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (42.25%)
 * Likes:    11404
 * Dislikes: 0
 * Total Accepted:    4.1M
 * Total Submissions: 9.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */

// @lc code=start
// 思路：滑动窗口
// 用 (start, i] 表示当前无重复字符的窗口（左开右闭），窗口长度为 i - start
// 用 dict 记录每个字符上次出现的下标，O(1) 检测重复，避免内层循环
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;

        // start：窗口左边界的前一个位置，初始为 -1（表示窗口可从下标 0 开始）
        int start = -1, maxlen = 0;

        // dict[c] 记录字符 c（按 ASCII 码索引）上次出现的下标，-1 表示未出现
        vector<int> dict(256, -1);

        for (int i = 0; i < n; i++) {
            // 若 s[i] 上次出现在窗口内（下标 > start），
            // 则必须把左边界收缩到该位置，排除重复字符
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }

            // 更新 s[i] 的最新出现位置
            dict[s[i]] = i;

            // 当前窗口长度为 i - start，尝试更新答案
            maxlen = max(maxlen, i - start);
        }
        return maxlen;
    }
};
// @lc code=end
