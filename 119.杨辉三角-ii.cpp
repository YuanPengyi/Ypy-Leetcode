/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (58.26%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 47.9K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> y;
        y.push_back(1);
        if(rowIndex == 0) return y;
        y.push_back(1);
        if(rowIndex == 1) return y;

        int front = 1;
        while(front < rowIndex){
            int fir = 0;
            int sec = 1;
            vector<int> tmp;
            tmp.push_back(1);
            while(sec <= front){
                tmp.push_back(y[fir] + y[sec]);
                fir = sec;
                sec++;
            }
            tmp.push_back(1);
            y = tmp;
            front++;
        }

        return y;
    }
};
// @lc code=end

