/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (67.10%)
 * Likes:    256
 * Dislikes: 0
 * Total Accepted:    34.5K
 * Total Submissions: 51.1K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return iterate(0, nums.size()-1, nums);
    }

    TreeNode* iterate(int start, int end, vector<int>& nums){
        int size = end - start + 1;
        int mid = start + size/2;
        TreeNode* root = new TreeNode(nums[mid]);

        if(start <= mid-1){
            TreeNode* left = iterate(start, mid-1, nums);
            root->left = left;
        }
            
        if(mid+1 <= end){
            TreeNode* right = iterate(mid+1, end, nums);
            root->right = right;
        }
        
        return root;
    }
};
// @lc code=end

