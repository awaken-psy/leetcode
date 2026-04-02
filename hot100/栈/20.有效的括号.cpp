/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (45.50%)
 * Likes:    4935
 * Dislikes: 0
 * Total Accepted:    2.5M
 * Total Submissions: 5.5M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "()"
 *
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "()[]{}"
 *
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(]"
 *
 * 输出：false
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "([])"
 *
 * 输出：true
 *
 *
 * 示例 5：
 *
 *
 * 输入：s = "([)]"
 *
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 *
 *
 */

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        stack<char> st;
        st.push(s[0]);
        int i = 1;  // 用于在string上移动
        while (!st.empty() || i < s.size()) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) return false;
                switch (ch) {
                    case ')':
                        if (st.top() == '(')
                            st.pop();
                        else
                            return false;
                        break;
                    case ']':
                        if (st.top() == '[')
                            st.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if (st.top() == '{')
                            st.pop();
                        else
                            return false;
                        break;
                    default:
                        return false;
                }
            }
            i++;
        }
        return true;
    }
};
// @lc code=end
