/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// version 0, non recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    vector<int> preorderTraversal1(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> stack;
        if (root == nullptr) {
            return result;
        }

        stack.push(root);
        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();
            result.push_back(node->val);
            if (node->right) {
                stack.push(node->right);
            }

            if (node->left) {
                stack.push(node->left);
            }
        }
        return result;
    }

    vector<int> preorderTraversal2(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        vector<int> left = preorderTraversal2(root->left);
        vector<int> right = preorderTraversal2(root->right);
        result.push_back(root->val);
        result.reserve(left.size() + right.size());
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }

private:
    void traversal(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        result.push_back(node->val);
        traversal(node->left, result);
        traversal(node->right, result);
    }
}