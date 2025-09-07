class Solution {
public:
    void dfs(TreeNode* root, string temp, string &ans) {
        if (!root) return;

        temp.push_back('a' + root->val);

        if (!root->left && !root->right) {
            string leafPath = temp;
            reverse(leafPath.begin(), leafPath.end());
            if (ans == "" || leafPath < ans) {
                ans = leafPath;
            }
            return;
        }

        dfs(root->left, temp, ans);
        dfs(root->right, temp, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        dfs(root, "", ans);
        return ans;
    }
};
