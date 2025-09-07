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

private:
    int maxDepth = 0;
    unordered_map<TreeNode*,int>mp;


public:


    TreeNode * LCA(TreeNode * root){
        if(!root)return NULL;
        if(mp[root]==maxDepth){
            return root;
        }

        TreeNode * left = LCA(root->left);
        TreeNode * right = LCA(root->right);

        if(left && right)return root;

        return left!=NULL?left:right;


    }


    void depthFind(TreeNode * root , int depth){
        if(!root)return;
        mp[root] = depth;
        if(root->left)depthFind(root->left,depth+1);
        if(root->right)depthFind(root->right,depth+1);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depthFind(root,0);
        for(auto &it : mp){
            if(it.second > maxDepth){
                maxDepth = it.second;
            }
        }
        return LCA(root);
    }
};