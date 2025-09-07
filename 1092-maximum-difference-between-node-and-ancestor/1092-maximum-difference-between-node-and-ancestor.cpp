/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dfs(TreeNode * root , int maxValue , int minValue){
        if(!root){
            return maxValue - minValue;
        }

        maxValue = max(maxValue , root->val);
        minValue = min(minValue , root->val);

        int left = dfs(root->left,maxValue,minValue);
        int right = dfs(root->right,maxValue,minValue);

        return max(left,right);

    }


    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val);
    }
};