/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (63.44%)
 * Likes:    3232
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 *
 *
 */

// @lc code=start
class Solution {
   private:
    vector<string> Solution;
    string letters;
    unordered_map<char, string> mp;
    void traceback(string digits, int level) {
        if (level == digits.length()) {
            Solution.push_back(letters);
            return;
        }
        for (char ch : mp[digits[level]]) {
            letters.push_back(ch);
            traceback(digits, level + 1);
            letters.pop_back();
        }
    }
    void initmap() {
        for (char ch = '2'; ch <= '9'; ch++) {
            switch (ch) {
                case '2':
                    mp[ch] = "abc";
                    break;
                case '3':
                    mp[ch] = "def";
                    break;
                case '4':
                    mp[ch] = "ghi";
                    break;
                case '5':
                    mp[ch] = "jkl";
                    break;
                case '6':
                    mp[ch] = "mno";
                    break;
                case '7':
                    mp[ch] = "pqrs";
                    break;
                case '8':
                    mp[ch] = "tuv";
                    break;
                case '9':
                    mp[ch] = "wxyz";
                    break;
            }
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        initmap();
        traceback(digits, 0);
        return Solution;
    }
};
// @lc code=end
