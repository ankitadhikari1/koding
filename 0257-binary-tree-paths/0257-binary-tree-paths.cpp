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
    void func(TreeNode * root, string temp,vector<string>&ans){
            temp+=to_string(root->val);
            if(root->left)
            func(root->left,temp+"->",ans);
            if(root->right)
            func(root->right,temp+"->",ans);
            if(!root->left && !root->right){
                ans.push_back(temp);
            }

        }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
            string temp = "";
            func(root,temp,ans);
            return ans;
    }
};