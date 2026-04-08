/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode.cn/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (55.48%)
 * Likes:    1149
 * Dislikes: 0
 * Total Accepted:    441.4K
 * Total Submissions: 795.3K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 *
 *
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 *
 *
 * 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 *
 * 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
 *
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] 仅为 0、1 或 2
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        while (!q.empty()) {
            int len = q.size();
            bool spread = false;
            for (int i = 0; i < len; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    spread = true;
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    spread = true;
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                }
                if (row + 1 < m && grid[row + 1][col] == 1) {
                    spread = true;
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                }
                if (col + 1 < n && grid[row][col + 1] == 1) {
                    spread = true;
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                }
            }
            if (spread) time++;//最后一轮不扩散
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
// @lc code=end
