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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        long long maxWidth = 1;
        queue<pair<TreeNode * , unsigned long long>>q;
        q.push({root,0});
        while(!q.empty()){
            unsigned long long size = q.size();
            unsigned long long left , right;
            unsigned long long mn = q.front().second;
            for(int i=0;i<size;i++){

                auto it = q.front();
                q.pop();
                auto node = it.first;
                auto ind = it.second - mn;
                if(i==0)left = ind;
                if(i==size-1)right = ind;

                if(node->left){
                    q.push({node->left,2*ind+1});
                }
                if(node->right){
                    q.push({node->right,2*ind+2});
                }

            }

            maxWidth = max(maxWidth,(long long)(right-left+1));
        }

        return (int)maxWidth;
    }
};