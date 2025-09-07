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

    int dfs(TreeNode * root , int &res){
        if(!root)return 0;
        int leftRoot = dfs(root->left,res);
        int rightRoot = dfs(root->right,res);
        int leftHeight = 0 ; int rightHeight = 0;
        if(root->left && root->left->val == root->val){
            leftHeight = leftRoot+1;
        }
        if(root->right && root->right->val == root->val){
            rightHeight = rightRoot+1;
        }

        res = max(res,leftHeight+rightHeight);

        return max(leftHeight,rightHeight);
    }


    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        dfs(root,res);
        return res;
    }
};