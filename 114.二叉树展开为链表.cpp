/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (65.44%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    16.8K
 * Total Submissions: 25.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    TreeNode* cur;
    void flatten(TreeNode* root) {
        if(root != NULL){
            cur = root;
            iterate(cur);
        }
    }

    void iterate(TreeNode* root){
        if(root->left != NULL && root->right != NULL){
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = NULL;
            cur = root->right;
            iterate(cur);
            cur->right = tmp;
            cur = tmp;
            iterate(cur);
        }else if(root->left != NULL){
            root->right = root->left;
            root->left = NULL;
            cur = root->right;
            iterate(cur);
        }else if(root->right != NULL){
            cur = root->right;
            iterate(cur);
        }else{
            return;
        }
    }
};
// @lc code=end

