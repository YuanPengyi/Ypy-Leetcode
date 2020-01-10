/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 *
 * https://leetcode-cn.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (52.74%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 16.9K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
 * 
 * 如果数组元素个数小于 2，则返回 0。
 * 
 * 示例 1:
 * 
 * 输入: [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 * 
 * 示例 2:
 * 
 * 输入: [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
 * 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 0) return 0;
        int size = nums.size();
        int min = INT_MAX, max = INT_MIN, res = 0;
        for(int i=0; i<size; i++){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }
        int gap = (max - min)/(size-1);
        if(gap == 0) gap = 1;
        vector<int> aa;
        vector<vector<int>> record((max-min)/gap+1, aa);
        // cout << min << " " << max << endl;
        // cout << gap << " " << size << endl;
        for(int i=0; i<size; i++){
            int tmp = (nums[i] - min)/gap;
            // cout << tmp << " " << nums[i] << endl;
            record[tmp].push_back(nums[i]);
        }
        
        int pre = min;
        for(int i=0; i<(max-min)/gap+1; i++){
            if(record[i].size() == 0) continue;
            int min_tmp = INT_MAX, max_tmp = INT_MIN;
            for(int j=0; j<record[i].size(); j++){
                if(record[i][j] > max_tmp) max_tmp = record[i][j];
                if(record[i][j] < min_tmp) min_tmp = record[i][j];
            }
            if(min_tmp - pre > res) res = min_tmp - pre;
            pre = max_tmp;
        }

        return res;
    }
};
// @lc code=end

