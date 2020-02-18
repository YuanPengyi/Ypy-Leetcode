/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 *
 * https://leetcode-cn.com/problems/dungeon-game/description/
 *
 * algorithms
 * Hard (38.91%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 16.7K
 * Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
 *
 * 
 * table.dungeon, .dungeon th, .dungeon td {
 * ⁠ border:3px solid black;
 * }
 * 
 * ⁠.dungeon th, .dungeon td {
 * ⁠   text-align: center;
 * ⁠   height: 70px;
 * ⁠   width: 70px;
 * }
 * 
 * 
 * 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N
 * 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
 * 
 * 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
 * 
 * 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为
 * 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
 * 
 * 为了尽快到达公主，骑士决定每次只向右或向下移动一步。
 * 
 * 
 * 
 * 编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
 * 
 * 例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。
 * 
 * 
 * ⁠
 * -2 (K) 
 * -3 
 * 3 
 * ⁠
 * ⁠
 * -5 
 * -10 
 * 1 
 * ⁠
 * ⁠
 * 10 
 * 30 
 * -5 (P) 
 * ⁠
 * 
 * [[1,-3,3],[0,-2,0],[-3,-3,-3]]
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 
 * 骑士的健康点数没有上限。
 * 
 * 任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> lifes;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<int> tmp(col, 0);
        for(int i=0; i<row; i++){
            lifes.push_back(tmp);
        }

        lifes[row-1][col-1] = max(1, 1-dungeon[row-1][col-1]);
        // cout << row << "|" << col << "|" << lifes[row-1][col-1] << endl;
        int tol = col + row -3;

        while(tol >= 0){
            int i;
            if(tol >= row-1) i = row-1;
            else i = tol;
            int j = tol - i;
            while(i >= 0 && i < row && j >= 0 && j < col){
                int fir = INT_MAX;
                int last = INT_MAX;
                if(i+1 < row){
                    fir = lifes[i+1][j];
                }
                if(j+1 < col){
                    last = lifes[i][j+1];
                }
                lifes[i][j] = max(1, min(fir, last)-dungeon[i][j]);
                
                
                // cout << i << "|" << j << "|" << lifes[i][j] << endl;

                i--;
                j++;
            }
            tol--;
        }

        return max(lifes[0][0], 1);
    }
};
// @lc code=end

