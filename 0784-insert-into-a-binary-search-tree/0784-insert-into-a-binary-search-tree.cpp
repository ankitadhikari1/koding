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

        TreeNode * func(TreeNode * root,int  val){
        if(!root->left && !root->right)return root;
        if((root->val < val && !root->right)||(root->val > val && !root->left))return root;
        if(root->val < val){
           return func(root->right,val);
        }
        return func(root->left,val);
    }


    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        TreeNode * parent = func(root,val);
        if(parent->val < val){
            parent->right = new TreeNode(val);
        }
        else{
            parent->left = new TreeNode(val);
        }
        return root;
    }
};