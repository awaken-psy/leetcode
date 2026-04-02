/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (78.98%)
 * Likes:    1411
 * Dislikes: 0
 * Total Accepted:    488.6K
 * Total Submissions: 618.7K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。例如，字符串 "ababcc" 能够被分为 ["abab",
 * "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。
 * 
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 * 
 * 返回一个表示每个字符串片段的长度的列表。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "eccbbbbdec"
 * 输出：[10]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 500
 * s 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        // ---------------------------------------------------------------
        // 第一步：预处理——记录每个字符在字符串中的【最后出现位置】
        // 用 vector<tuple<char, int, int>> 存储三元组：
        // (字符, 首次出现下标, 最后出现下标)
        // ---------------------------------------------------------------
        vector<tuple<char, int, int>> table;

        for (int i = 0; i < n; i++) {
            char target = s[i];

            auto it = std::find_if(table.begin(), table.end(), [target](const auto& t) {
                return std::get<0>(t) == target;  // 取元组第 0 个元素（字符）比较
            });

            if (it != table.end()) {
                // 字符已存在：用 std::distance 计算迭代器到 begin 的距离，得到下标
                int index = std::distance(table.begin(), it);
                // 更新该字符的最后出现位置为当前下标 i
                get<2>(table[index]) = i;
            } else {
                // 字符首次出现：插入 (字符, 首次下标i, 最后下标i)
                // emplace_back 直接在末尾原地构造，避免拷贝（比 push_back 更高效）
                table.emplace_back(s[i], i, i);
            }
        }

        // ---------------------------------------------------------------
        // 第二步：贪心扫描——确定每个片段的边界
        // ---------------------------------------------------------------
        int submax = 0;  // 当前片段右边界（能延伸到的最远下标）
        int sublen = 1;  // 当前片段长度（从 1 开始，因为循环末尾 sublen++ 在 i++ 之前执行）
        vector<int> output;

        for (int i = 0; i < n; i++, sublen++) {
            char target = s[i];

            // 查找当前字符在 table 中的记录（同上，用 find_if + lambda）
            auto it = std::find_if(table.begin(), table.end(), [target](const auto& t) {
                return std::get<0>(t) == target;
            });
            int index = std::distance(table.begin(), it);

            // 用当前字符的最后出现下标更新本片段右边界
            // 贪心关键：右边界只能扩大，不能缩小
            submax = max(submax, get<2>(table[index]));

            // 当前下标追上右边界：当前片段结束，记录长度并重置
            if (i >= submax) {
                output.emplace_back(sublen);
                sublen = 0;  // 重置为 0，下次循环的 sublen++ 会让它变成 1
            }
        }
        return output;
    }
};
// vector<int> partitionLabels(string s) {
//     // last[c] 存储字符 c 在 s 中最后出现的下标
//     // 用 256 大小的数组直接以 ASCII 值做索引，比 map 快
//     int last[256]{0};
//     for (int i = 0; i < (int)s.size(); ++i)
//         last[s[i]] = i;

//     vector<int> result;
//     int segStart = 0;   // 当前片段的起始下标
//     int segEnd   = 0;   // 当前片段能延伸到的最远下标

//     for (int i = 0; i < (int)s.size(); ++i) {
//         // 右边界只扩不缩：遇到新字符就看它最后出现的位置能否撑得更远
//         segEnd = max(segEnd, last[s[i]]);

//         // i 追上 segEnd：片段内所有字符都"收口"了，可以在此切断
//         if (i == segEnd) {
//             result.push_back(segEnd - segStart + 1);
//             segStart = i + 1;   // 下一片段从下一个字符开始
//         }
//     }

//     return result;
// }
// @lc code=end

