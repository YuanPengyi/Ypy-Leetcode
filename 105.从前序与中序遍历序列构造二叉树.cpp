/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (61.87%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    26.9K
 * Total Submissions: 43.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
[1,2,4,5,3,6,7]
[4,2,5,1,6,3,7]
[1,3,6,7]\n[1,6,3,7]

 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        iterate(root, 0, 0, inorder.size()-1, preorder, inorder);

        return root;
    }

    void iterate(TreeNode* root, int root1, int start, int end, vector<int>& preorder, vector<int>& inorder){
        vector<int>::iterator root2 = std::find(inorder.begin(), inorder.end(), preorder[root1]);
        int index = std::distance(inorder.begin(), root2);
        int leftlen = index - start;
        int rightlen = end - index;

        if(leftlen != 0){
            TreeNode* t1 = new TreeNode(preorder[root1+1]);
            root->left = t1;
            iterate(t1, root1+1, start, index-1, preorder, inorder);
        }
            
        if(rightlen != 0){
            TreeNode* t2 = new TreeNode(preorder[root1+leftlen+1]);
            root->right = t2;
            iterate(t2, root1+leftlen+1, index+1, end, preorder, inorder);
        }
            
    }
};
// @lc code=end

