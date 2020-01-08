/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 *
 * https://leetcode-cn.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (40.15%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    2.8K
 * Total Submissions: 6.8K
 * Testcase Example:  '[0,1]'
 *
 * 给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组（的长度）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [0,1]
 * 输出: 2
 * 说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
 * 
 * 示例 2:
 * 
 * 输入: [0,1,0]
 * 输出: 2
 * 说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 * 
 * 
 * 
 * 注意: 给定的二进制数组的长度不会超过50000。
 * 
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) nums[i] = -1;
        }
        int dp[50002];
        dp[0] = 0;
        map[0] = -1;
        for(int i=0; i<nums.size(); i++){
            dp[i+1] = dp[i] + nums[i];
            if(map.find(dp[i+1]) == map.end()){
                map[dp[i+1]] = i;
            }else{
                int tmp = i - map[dp[i+1]];
                // cout << i << " " << map[dp[i+1]] << " -- " << dp[i+1] << endl;
                if(tmp > res) res = tmp; 
            }
        }

        return res;
    }
};
// @lc code=end

