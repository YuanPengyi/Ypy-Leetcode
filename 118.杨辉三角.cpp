/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (64.20%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    43.6K
 * Total Submissions: 67.6K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> y;
        if(numRows == 0) return res;
        y.push_back(1);
        res.push_back(y);
        if(numRows == 1) return res;
        y.push_back(1);
        res.push_back(y);
        if(numRows == 2) return res;
        numRows = numRows - 2;

        int front = 1;
        while(front <= numRows){
            int fir = 0;
            int sec = 1;
            vector<int> tmp;
            tmp.push_back(1);
            while(sec <= front){
                tmp.push_back(res[front][fir] + res[front][sec]);
                fir = sec;
                sec++;
            }
            tmp.push_back(1);
            res.push_back(tmp);
            front++;
        }

        return res;
    }
};
// @lc code=end

