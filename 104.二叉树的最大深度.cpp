/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (71.08%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    85K
 * Total Submissions: 119.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
    int res = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        find(1, root);

        return res;
    }
    
    void find(int deep, TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            // cout << deep << " ";
            if(deep > res) res = deep;
            return;
        }
        deep++;
        if(root->left) find(deep, root->left);
        if(root->right) find(deep, root->right);
    }
    
    /*
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return 0;
        q.push(root);
        int deep = 0;
        while(!q.empty()){
            int cnt = q.size();
            while(cnt != 0){
                cnt--;
                TreeNode* node = q.front();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
            }
            deep++;
        }

        return deep;
    }*/
};
// @lc code=end

