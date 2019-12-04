/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (44.13%)
 * Likes:    2292
 * Dislikes: 62
 * Total Accepted:    277.7K
 * Total Submissions: 625.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
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
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        int index = 0;
        int root_val = preorder[index++];
        bool isLeft = true;
        vector<int> p1, p2;
        vector<int> i1, i2;

        for (int i = 0; i < preorder.size(); i++) {
            if (inorder[i] == root_val) {
                isLeft = false;
                continue;
            }
            if (isLeft) {
                i1.push_back(inorder[i]);
                p1.push_back(preorder[index++]);
            } else {
                i2.push_back(inorder[i]);
                p2.push_back(preorder[index++]);
            }
        }

        TreeNode* root = new TreeNode(root_val);
        root->left = buildTree(p1, i1);
        root->right = buildTree(p2, i2);
        return root;
    }
};
// @lc code=end

