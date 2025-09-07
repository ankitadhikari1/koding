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

        //inc exc
    //pair<int,int>



    pair<int,int> func(TreeNode * root){
        if(!root)return {0,0};

        auto left = func(root->left);
        auto right = func(root->right);

        int val = root->val;

        int include = val + left.second + right.second;
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include,exclude};

        
    }


    int rob(TreeNode* root) {
        auto node = func(root);
        return max(node.first,node.second);
    }
};