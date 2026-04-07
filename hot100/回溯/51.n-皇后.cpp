/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (75.41%)
 * Likes:    2461
 * Dislikes: 0
 * Total Accepted:    670K
 * Total Submissions: 888.6K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 *
 *
 *
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
   private:
    int n;
    vector<vector<string>> Solution;
    vector<string> board;

    bool issafe(int row, int col) {
        // checkrow
        for (int i = 0; i < col; i++)
            if (board[row][i] == 'Q') return false;

        // check leftup
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        // check leftdown
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    void traceback(int col) {
        if (col == n) {
            Solution.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (issafe(i, col)) {
                board[i][col] = 'Q';
                traceback(col + 1);
                board[i][col] = '.';
            }
        }

        return;
    }

   public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.resize(n, string(n, '.'));
        traceback(0);
        return Solution;
    }
};
// @lc code=end
