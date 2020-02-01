/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (51.59%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    62.4K
 * Total Submissions: 119.8K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0; i<numbers.size()-1; i++){
            int j = i+1;
            while(numbers[j]+numbers[i] < target){
                j++;
                if(numbers.size() == j) break;
            }
            if(numbers.size() == j) continue;
            if(numbers[j]+numbers[i] == target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
        }

        return res;
    }
};
// @lc code=end

