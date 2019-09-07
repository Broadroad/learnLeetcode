/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     * 
     * 分治法 和 打擂台
     */
    TreeNode * findSubtree(TreeNode * root) {
        if (root == nullptr) {
            return root;
        }
        
        findSubtreeHelper(root);
        return subtree;
    }
private:
    TreeNode *subtree = nullptr;
    int minimumSub = INT_MAX;
    
    int findSubtreeHelper(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        int sum = findSubtreeHelper(root->left) + findSubtreeHelper(root->right) + root->val;
        
        if (minimumSub > sum) {
            minimumSub = sum;
            subtree = root;
        }
        return sum;
    }
};