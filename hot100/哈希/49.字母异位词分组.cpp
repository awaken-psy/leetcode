/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (69.65%)
 * Likes:    2652
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2.2M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 *
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 解释：
 *
 *
 * 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
 * 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
 * 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
 *
 *
 *
 * 示例 2:
 *
 *
 * 输入: strs = [""]
 *
 * 输出: [[""]]
 *
 *
 * 示例 3:
 *
 *
 * 输入: strs = ["a"]
 *
 * 输出: [["a"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
   public:
    string strSort(string& s) {
        int counter[26] = {0};
        for (char ch : s) {
            counter[ch - 'a']++;
        }
        string res;
        for (int i = 0; i < 26; i++) {
            res += string(counter[i], 'a' + i);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }

        vector<vector<string>> res;
        for (auto p : mp) {
            res.push_back(p.second);
        }

        return res;
    }
};
// @lc code=end
