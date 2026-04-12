/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (40.61%)
 * Likes:    8047
 * Dislikes: 0
 * Total Accepted:    2.3M
 * Total Submissions: 5.7M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
   public:
    string expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;   
            right++;  
        }
        // 退出循环时，left 和 right 已经多走了一步（不满足条件了）
        // 所以实际回文范围是 (left+1, right-1)，长度是 (right-1) - (left+1) + 1 = right - left - 1
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        if (s.size() == 1) return s;

        string result = "";  // 存储当前找到的最长回文子串

        // 枚举每个位置作为中心
        for (int i = 0; i < s.size(); i++) {
            // 情况1：以单个字符为中心（奇数长度回文）
            string odd = expandAroundCenter(s, i, i);

            // 情况2：以两个字符之间为中心（偶数长度回文）
            // 中心是 s[i] 和 s[i+1] 之间
            string even = expandAroundCenter(s, i, i + 1);

            // 取两种情况中更长的
            string current = odd.size() > even.size() ? odd : even;

            // 如果当前找到的回文比之前记录的更长，更新结果
            if (current.size() > result.size()) {
                result = current;
            }
        }

        return result;
    }
};

/*
bool isPalindrome(string& s, int i, int j) {
    if (j > i) swap(i, j);
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++, j--;
    }
    return true;
}

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0 || n == 1) return s;

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    string ans = "";
    ans += s[0];

    // 从右往左遍历起始位置 i（关键：保证 dp[i+1][j-1] 已被计算）
    for (int i = n - 1; i >= 0; i--) {
        // 从 i+1 往右遍历结束位置 j，检查子串 s[i..j]
        for (int j = i + 1; j < n; j++) {
            // 首尾字符相同是回文的必要条件
            if (s[i] == s[j]) {
                // 满足以下任一条件，则 s[i..j] 为回文：
                // 1. j - i == 1：相邻两个字符相同（如 "bb"）
                // 2. dp[i+1][j-1]：去掉首尾后的子串已经是回文（递推关系）
                if (j - i == 1 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    // 如果当前回文子串更长，则更新答案
                    if (ans.size() < j - i + 1) ans = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return ans;
}

*/
// @lc code=end
