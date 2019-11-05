/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (64.70%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    15.7K
 * Total Submissions: 24.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        iterate(root, postorder.size()-1, 0, postorder.size()-1, inorder, postorder);

        return root;
    }

    void iterate(TreeNode* root, int root1, int start, int end, vector<int>& inorder, vector<int>& postorder){
        vector<int>::iterator iter = std::find(inorder.begin(), inorder.end(), postorder[root1]);
        int index = std::distance(inorder.begin(), iter);
        int leftlen = index - start;
        int rightlen = end - index;

        if(rightlen > 0){
            int x1 = root1-1;
            TreeNode* t2 = new TreeNode(postorder[x1]);
            root->right = t2;
            iterate(t2, x1, index+1, end, inorder, postorder);
        }

        if(leftlen > 0){
            int x2 = root1-rightlen-1;
            TreeNode* t1 = new TreeNode(postorder[x2]);
            root->left = t1;
            iterate(t1, x2, start, index-1, inorder, postorder);
        }
    }
};
// @lc code=end

