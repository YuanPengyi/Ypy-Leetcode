/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (57.24%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 24.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    int index[1000] = {0};
    int n;
    vector<int> tmp;
    vector<vector<int>> res;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        if(n == 0) return res;

        index[n-1] = n-1;
        for(int i=n-1; i>0; i--){
            if(nums[i] == nums[i-1]){
                index[i-1] = index[i];
            }else{
                index[i-1] = i-1;
            }
        }
        
        res.push_back(tmp);
        iterate(-1, nums);

        return res;
    }

    void iterate(int pos, vector<int>& nums){
        /*
        if(len == cnt){
            res.push_back(tmp);
            return;
        }*/
        int i = 0;

        i = pos + 1;
        while(i < n){
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            iterate(i, nums);
            tmp.pop_back();
            i = index[i] + 1;
        }
    }
};
// @lc code=end

