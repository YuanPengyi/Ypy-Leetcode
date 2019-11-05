/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (49.13%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 68.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
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
    bool res = true;

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        iterate(root);

        return res;
    }

    int iterate(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return 1;
        }

        if(root->left != NULL && root->right != NULL){
            int left = iterate(root->left);
            int right = iterate(root->right);

            if(left==-1 || right==-1) return -1;

            // cout << left << " " << right << endl;

            if(abs(left-right) > 1){
                res = false;
                return -1;
            } 

            return(max(left, right)+1);
        }else if(root->left != NULL){
            int left = iterate(root->left);
            if(left==-1) return -1;
            if(left > 1){
                res = false;
                return -1;
            } 

            return left+1;
        }else{
            int right = iterate(root->right);
            if(right==-1) return -1;
            if(right > 1){
                res = false;
                return -1;
            } 

            return right+1;
        }
    }
};
// @lc code=end

