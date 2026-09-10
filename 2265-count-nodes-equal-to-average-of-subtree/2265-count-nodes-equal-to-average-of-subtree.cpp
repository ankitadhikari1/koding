class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        func(root, count);
        return count;
    }

    pair<int, int> func(TreeNode* node, int& count) {
        if (node == nullptr) {
            return {0, 0};
        }

        auto left = func(node->left, count);
        auto right = func(node->right, count);

        int sum = node->val + left.first + right.first;
        int nodes = 1 + left.second + right.second;

        int average = sum / nodes;

        if (average == node->val) {
            count++;
        }

        return {sum, nodes};
    }
};