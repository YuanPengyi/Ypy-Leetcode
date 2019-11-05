/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (62.06%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    27.4K
 * Total Submissions: 44K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        int *dp = new int[triangle.size()];
        dp[0] = triangle[0][0];
        int x = 1;
        while(x < triangle.size()){
            int y = 0;
            int dpf = 0;
            while(y <= x){
                if(y == 0){
                    dpf = dp[0];
                    dp[0] = dp[0] + triangle[x][y];
                } 
                else if(y == x){
                    dp[y] = dpf + triangle[x][y];
                } 
                else{
                    int k = dp[y];
                    dp[y] = min(dpf + triangle[x][y], 
                                    dp[y] + triangle[x][y]);
                    dpf = k;
                }
                y++;
            }
            /*for(int i=0; i<=x; i++){
                cout << dp[i] << " ";
            }cout << endl;*/
            x++;
        }

        int res = dp[0];
        for(int i=1; i<triangle.size(); i++){
            if(dp[i] < res) res = dp[i];
        }

        return res;
    }
};
// @lc code=end

