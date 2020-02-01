/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (60.95%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    102.8K
 * Total Submissions: 167.9K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> record;
        for(int i=0; i<nums.size(); i++){
            if(record.count(nums[i]) == 0){
                record[nums[i]] = 1;
            }else{
                record[nums[i]]++;
            }
            if(record[nums[i]] > nums.size()/2) return nums[i];
        }

        return 0;
    }
};
// @lc code=end

