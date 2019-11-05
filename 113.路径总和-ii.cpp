/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (57.15%)
 * Likes:    134
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 33.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
    vector<vector<int>> res;
    vector<int> restmp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL) return res;

        restmp.push_back(root->val);
        iterate(root, sum, root->val);

        return res;
    }

    void iterate(TreeNode* root, int sum, int h){
        if(root->left != NULL && root->right != NULL){
            restmp.push_back(root->left->val);
            iterate(root->left, sum, h+root->left->val);
            restmp.pop_back();

            restmp.push_back(root->right->val);
            iterate(root->right, sum, h+root->right->val);
            restmp.pop_back();
        }else if(root->left == NULL && root->right == NULL){
            if(h == sum){
                res.push_back(restmp);
            } 
        }else if(root->left != NULL){
            restmp.push_back(root->left->val);
            iterate(root->left, sum, h+root->left->val);
            restmp.pop_back();
        }else{
            restmp.push_back(root->right->val);
            iterate(root->right, sum, h+root->right->val);
            restmp.pop_back();
        }
    }
};
// @lc code=end

