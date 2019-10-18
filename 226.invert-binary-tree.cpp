/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (60.01%)
 * Likes:    2106
 * Dislikes: 35
 * Total Accepted:    372.5K
 * Total Submissions: 620.6K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 * 
 * Example:
 * 
 * Input:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * Output:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * 
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
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
    TreeNode* invertTree1(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* tmp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(tmp);
        return root;
    }

    TreeNode* invertTree2(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
        }
        return root;
    }
    


};
// @lc code=end

