/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (59.11%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    50.6K
 * Total Submissions: 85.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root == NULL) return res;
        q.push(root);
        int cnt = 1;
        while(cnt != 0){
            int tmp = 0;
            vector<int> tmpres;
            while(cnt != 0){
                cnt--;
                TreeNode* node = q.front();
                tmpres.push_back(node->val);
                if(node->left != NULL){
                    tmp++;
                    q.push(node->left);
                }
                if(node->right != NULL){
                    tmp++;
                    q.push(node->right);
                }
                q.pop();
            }
            res.push_back(tmpres);
            cnt = tmp;
        }

        return res;
    }
};
// @lc code=end

