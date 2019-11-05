/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (45.50%)
 * Likes:    325
 * Dislikes: 0
 * Total Accepted:    74.5K
 * Total Submissions: 163.8K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tag1, tag2;
        tag1 = tag2 = 0;
        vector<int> nums;
        while(tag1 != m && tag2 != n){
            if(nums1[tag1] < nums2[tag2]){
                nums.push_back(nums1[tag1]);
                tag1++;
            }else{
                nums.push_back(nums2[tag2]);
                tag2++;
            }
        }
        
        if(tag1 == m){
            while(tag2 != n){
                nums.push_back(nums2[tag2]);
                tag2++;
            }
        }else{
            while(tag1 != m){
                nums.push_back(nums1[tag1]);
                tag1++;
            }
        }
        tag1 = 0;
        while(tag1 != m+n){
            nums1[tag1] = nums[tag1];
            tag1++;
        }
    }
};
// @lc code=end

