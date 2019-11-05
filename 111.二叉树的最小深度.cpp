/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.28%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    35.5K
 * Total Submissions: 87.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        return iterate(root);
    }

    int iterate(TreeNode* root){
        int left, right;
        if(root->left == NULL && root->right == NULL){
            return 1;
        }else if(root->left !=NULL && root->right != NULL){
            left = iterate(root->left);
            right = iterate(root->right);

            return (min(left, right)+1);
        }else if(root->left != NULL){
            left = iterate(root->left);

            return left+1;
        }else{
            right = iterate(root->right);

            return right+1;
        }
    }
};
// @lc code=end

