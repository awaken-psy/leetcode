/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (55.04%)
 * Likes:    2110
 * Dislikes: 0
 * Total Accepted:    968.6K
 * Total Submissions: 1.8M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -100
 *
 *
 */

// @lc code=start
class Solution {
   private:
    enum Direction { left, right, up, down };
    Direction dir;

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        dir = (n > 1) ? right : down;

        int stepx = n - 1;
        int stepy = m - 1;
        int curx = 0, cury = 0;
        res.push_back(matrix[cury][curx]);
        for (int idx = 0;; idx++) {
            if ((dir == up || dir == down) && stepy == 0) break;
            if ((dir == left || dir == right) && stepx == 0) break;
            switch (dir) {
                case up:
                    for (int i = 1; i <= stepy; i++) {
                        res.push_back(matrix[cury - i][curx]);
                    }
                    cury -= stepy;
                    if (idx != 0) stepy--;
                    dir = right;
                    break;
                case down:
                    for (int i = 1; i <= stepy; i++) {
                        res.push_back(matrix[cury + i][curx]);
                    }
                    cury += stepy;
                    if (idx != 0) stepy--;
                    dir = left;
                    break;
                case left:
                    for (int i = 1; i <= stepx; i++) {
                        res.push_back(matrix[cury][curx - i]);
                    }
                    curx -= stepx;
                    if (idx != 0) stepx--;
                    dir = up;
                    break;
                case right:
                    for (int i = 1; i <= stepx; i++) {
                        res.push_back(matrix[cury][curx + i]);
                    }
                    curx += stepx;
                    if (idx != 0) stepx--;
                    dir = down;
                    break;
            }
        }
        return res;
    }
};
// @lc code=end
