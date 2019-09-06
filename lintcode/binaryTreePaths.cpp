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
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> paths;
        if (root == nullptr) {
            return paths;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return { to_string(root->val) };
        }
        
        vector<string> leftPaths = binaryTreePaths(root->left);
        vector<string> rightPaths = binaryTreePaths(root->right);
        
        
        for (string path : leftPaths) {
            paths.push_back(to_string(root->val) + "->" + path);
        }
        
        for (string path : rightPaths) {
            paths.push_back(to_string(root->val) + "->" + path);
        }
        
        return paths;
    }
};