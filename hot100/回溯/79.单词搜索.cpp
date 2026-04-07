/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode.cn/problems/word-search/description/
 *
 * algorithms
 * Medium (50.78%)
 * Likes:    2177
 * Dislikes: 0
 * Total Accepted:    875.8K
 * Total Submissions: 1.7M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true
 * ；否则，返回 false 。
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word =
 * "ABCCED"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word =
 * "SEE"
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word =
 * "ABCB"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board 和 word 仅由大小写英文字母组成
 *
 *
 *
 *
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 *
 */

// @lc code=start
class Solution {
   private:
    vector<vector<bool>> visited;

    bool traceback(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        if (board[row][col] != word[idx]) {
            return false;
        }
        if (idx + 1 == (int)word.size()) {
            return true;
        }
        visited[row][col] = true;

        if (row - 1 >= 0 && !visited[row - 1][col])
            if (traceback(board, word, idx + 1, row - 1, col)) return true;

        if (col - 1 >= 0 && !visited[row][col - 1])
            if (traceback(board, word, idx + 1, row, col - 1)) return true;

        if (row + 1 < (int)board.size() && !visited[row + 1][col])
            if (traceback(board, word, idx + 1, row + 1, col)) return true;

        if (col + 1 < (int)board[0].size() && !visited[row][col + 1])
            if (traceback(board, word, idx + 1, row, col + 1)) return true;

        visited[row][col] = false;  // 回溯撤销

        return false;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        bool reach = false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                visited.assign(board.size(), vector<bool>(board[0].size(), false));
                reach = traceback(board, word, 0, i, j);
                if (reach) return true;
            }
        }
        return false;
    }
};
/*标答
bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++)
        for (unsigned int j = 0; j < board[0].size(); j++)
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])
        return false;
    char c = board[i][j];
    board[i][j] = '*';              //*不会和字符匹配，替代visit数组（来的路上都是*）
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board,i, j+1, s); 
    board[i][j] = c; 
    return ret;
}

*/
// @lc code=end
