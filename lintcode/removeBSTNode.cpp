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
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        // write your code here
        TreeNode* dummy = new TreeNode(-1);
        dummy->left = root;
        TreeNode* parent = findNode(dummy, root, value);
        TreeNode *node;

        if (parent->left && parent->left->val == value) {
            node = parent->left;
        } else if (parent->right && parent->right->val == value) {
            node = parent->right;
        } else {
            return dummy->left;
        }

        deleteNode(parent, node);
        return dummy->left;
    }

private:
    TreeNode* findNode(TreeNode* parent, TreeNode* node, int value) {
        if (node == NULL) {
            return parent;
        }

        if (node->val == value) {
            return parent;
        }

        if (value < node->val) {
            return findNode(node, node->left, value);
        } else {
            return findNode(node, node->right, value);
        }
    }

    void deleteNode(TreeNode* parent, TreeNode* node) {
        if (node->right == NULL) {
           if (parent->left == node) {
               parent->left = node->left;
           } else {
               parent->right = node->left;
           }
        } else {
            TreeNode* tmp = node->right;
            TreeNode* father = node;

            while (tmp->left) {
                father = tmp;
                tmp = tmp->left;
            }

            if (father->left == tmp) {
                father->left = tmp->right;
            } else {
                father->right = tmp->right;
            }

            if (parent->left == node) {
                parent->left = tmp;
            } else {
                parent->right = tmp;
            }

            tmp->left = node->left;
            tmp->right = node->right;
        }
    }

};