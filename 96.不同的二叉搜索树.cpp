/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (62.43%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 29.2K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        int cnt;
        vector<int> res;
        res.push_back(1);
        res.push_back(1);
        res.push_back(2);
        cnt = 3;
        while(cnt <= n){
            int i = 0;
            int j = cnt-1;
            int tmp = 0;
            while(i < j){
                tmp += res[i] * res[j] * 2;
                i++;
                j--;
            }
            if(i == j) tmp += res[i]*res[i];

            res.push_back(tmp);
            cnt++;
        }

        return res[n];
    }
};
// @lc code=end

