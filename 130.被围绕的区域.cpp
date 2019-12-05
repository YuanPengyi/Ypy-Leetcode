/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (38.18%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    15.7K
 * Total Submissions: 40.8K
 * Testcase Example:  '[["X","O","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */

// @lc code=start
class Solution {
public:
    int visited[2000][2000];
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        if(col == 0) return;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                visited[i][j] = 0;
            }
        }

        for(int j=0; j<col; j++){
            if(board[0][j] == 'O'){
                dfs(board, 0, j, row, col);
            }
            if(board[row-1][j] == 'O'){
                dfs(board, row-1, j, row, col);
            }
        }

        for(int i=0; i<row; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0, row, col);  
            }
            if(board[i][col-1] == 'O'){
                dfs(board, i, col-1, row, col);  
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(visited[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y, int row, int col){
        visited[x][y] = 1;
        if(x+1 < row && board[x+1][y] == 'O' && visited[x+1][y] == 0){
            visited[x+1][y] = 1;
            dfs(board, x+1, y, row, col);
        }
        if(y+1 < col && board[x][y+1] == 'O' && visited[x][y+1] == 0){
            visited[x][y+1] = 1;
            dfs(board, x, y+1, row, col);
        }
        if(x-1 >= 0 && board[x-1][y] == 'O' && visited[x-1][y] == 0){
            visited[x-1][y] = 1;
            dfs(board, x-1, y, row, col);
        }
        if(y-1 >= 0 && board[x][y-1] == 'O' && visited[x][y-1] == 0){
            visited[x][y-1] = 1;
            dfs(board, x, y-1, row, col);
        }
    }
};
// @lc code=end

