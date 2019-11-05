/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (68.42%)
 * Likes:    107
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 17.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head = head->next;
        }
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

