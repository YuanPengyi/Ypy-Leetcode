/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (63.17%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    58.5K
 * Total Submissions: 92.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(root == NULL) return res;
        s.push(root);
        res.push_back(root->val);
        while(!s.empty()){
            TreeNode* tmp = s.top();
            if(tmp->left != NULL){
                res.push_back(tmp->left->val);
                s.push(tmp->left);
                tmp->left = NULL;
            }else if(tmp->right != NULL){
                res.push_back(tmp->right->val);
                s.push(tmp->right);
                tmp->right = NULL;
            }else{
                s.pop();
            }
        }

        return res;
    }
};
// @lc code=end

