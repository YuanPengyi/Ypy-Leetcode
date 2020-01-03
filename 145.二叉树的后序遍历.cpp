/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (69.36%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    43.7K
 * Total Submissions: 63.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(root == NULL) return res;
        s.push(root);
        while(!s.empty()){
            TreeNode* tmp = s.top();
            bool flag = 1;
            if(tmp->right != NULL){
                s.push(tmp->right);
                tmp->right = NULL;
                flag = 0;
            }
            if(tmp->left != NULL){
                s.push(tmp->left);
                tmp->left = NULL;
                flag = 0;
            }
            if(flag){
                res.push_back(tmp->val);
                s.pop();
            }
        }

        return res;
    }
};
// @lc code=end

