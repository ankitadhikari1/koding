class Solution {
public:
    void dfs(TreeNode* root, int& sum, int num) {
        if (!root) return;

        
        num = (num << 1) | root->val;

        
        if (!root->left && !root->right) {
            sum += num;
            return;
        }

        dfs(root->left, sum, num);
        dfs(root->right, sum, num);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }
};
