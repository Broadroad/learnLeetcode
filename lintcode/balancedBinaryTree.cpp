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
 

class ResultType {
public:
    bool isBalanced;
    int height;
    
    ResultType(bool isBalanced, int height) : height(height), isBalanced(isBalanced) {};
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        if (root == nullptr) {
            return true;
        }
        
        ResultType result = helper(root);
        return result.isBalanced;
    }
private:
    ResultType helper(TreeNode *root) {
        if (root == nullptr) {
            return ResultType(true, 0);
        } 
        
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        
        if (!left.isBalanced || !right.isBalanced || abs(left.height - right.height) > 1) {
            return ResultType(false, max(left.height, right.height)+1);
        }
        
        return ResultType(true, max(left.height, right.height)+1);
    }
};