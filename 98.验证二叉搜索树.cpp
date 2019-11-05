/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98
 ] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (27.70%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    43.7K
 * Total Submissions: 157.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * [5,1,4,3,6]
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return iterate(root, LONG_MIN, LONG_MAX);
    }

    bool iterate(TreeNode* root, long min, long max){
        if(root == NULL) return true;
        bool res = true;
        if(root->left != NULL && root->left->val < root->val && root->left->val > min){
            res = res && iterate(root->left, min, root->val); 
        }else if(root->left != NULL && (root->left->val >= root->val || root->left->val <= min)){
            return false;
        }
        if(root->right != NULL && root->right->val > root->val && root->right->val < max){
            res = res && iterate(root->right, root->val, max);
        }else if(root->right != NULL && (root->right->val <= root->val || root->right->val >= max)){
            return false;
        }

        return res;
    }
};
// @lc code=end

