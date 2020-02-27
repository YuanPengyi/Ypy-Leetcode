/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (62.31%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    18.6K
 * Total Submissions: 29.2K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        int deepth = 1;
        int cnt = 1;
        while(!s.empty()){
            res.push_back(s.top()->val);
            stack<TreeNode*> record;
            while(cnt != 0){
                TreeNode* tmp = s.top();
                if(tmp->right != NULL){
                    record.push(tmp->right);
                }
                if(tmp->left != NULL){
                    record.push(tmp->left);
                }
                s.pop();
                cnt--;
            }
            while(!record.empty()){
                TreeNode* tmp = record.top();
                s.push(tmp);
                record.pop();
                cnt++;
            }
        }

        return res;
    }
};
// @lc code=end

