/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (59.44%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 20.3K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        
        if(n == 0){
            return res;
        }
        res = iterate(1, n);

        return res;
    }

    vector<TreeNode*> iterate(int l, int r){
        vector<TreeNode*> ret;
        if(l > r){
            ret.push_back(nullptr);
            return ret;
        }
        for(int i=l; i<=r; i++){
            vector<TreeNode*> leftTree = iterate(l, i-1);
            vector<TreeNode*> rightTree = iterate(i+1, r);

            for(auto lt : leftTree){
                for(auto rt : rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;

                    ret.push_back(root);
                }
            }
        }

        return ret;
    }
};
// @lc code=end

