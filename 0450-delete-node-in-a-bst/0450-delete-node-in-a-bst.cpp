/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class Solution {
public:

    // Search for a node with given key, also update parent reference
    TreeNode* search(TreeNode* root, int key, TreeNode*& parent) {
        if (!root) return nullptr;

        if (root->val == key) return root;

        parent = root;
        if (key > root->val)
            return search(root->right, key, parent);
        else
            return search(root->left, key, parent);
    }

    // Find leftmost node in a subtree
    TreeNode* findLeftEnd(TreeNode* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }

    // Find rightmost node in a subtree
    TreeNode* findRightEnd(TreeNode* root) {
        while (root && root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        TreeNode* parent = nullptr;
        TreeNode* node = search(root, key, parent);
        if (!node) return root; // Key not found

        // Case 1: Deleting the root node
        if (!parent) {
            if (!node->left && node->right) return node->right;
            if (!node->right && node->left) return node->left;
            if (!node->left && !node->right) return nullptr;

            // Both children
            TreeNode* temp = node->left;
            TreeNode* leftEnd = findLeftEnd(node->right);
            root = node->right;
            leftEnd->left = temp;
            return root;
        }

        // Case 2: Node is left child of parent
        if (parent->left == node) {
            if (!node->left && node->right) {
                parent->left = node->right;
            }
            else if (!node->right && node->left) {
                parent->left = node->left;
            }
            else if (!node->left && !node->right) {
                parent->left = nullptr;
            }
            else {
                TreeNode* temp = node->left;
                TreeNode* leftEnd = findLeftEnd(node->right);
                parent->left = node->right;
                leftEnd->left = temp;
            }
        }
        // Case 3: Node is right child of parent
        else {
            if (!node->left && node->right) {
                parent->right = node->right;
            }
            else if (!node->right && node->left) {
                parent->right = node->left;
            }
            else if (!node->left && !node->right) {
                parent->right = nullptr; 
            }
            else {
                TreeNode* temp = node->right;
                TreeNode* rightEnd = findRightEnd(node->left);
                parent->right = node->left;
                rightEnd->right = temp;
            }
        }

        return root;
    }
};
