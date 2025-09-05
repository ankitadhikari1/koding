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

    void func(TreeNode * root, int & cnt, int biggest){
        if(!root)return;
        if(root->val >= biggest){
            biggest = root->val;
            cnt+=1;
        }
        if(root->left)func(root->left,cnt,biggest);
        if(root->right)func(root->right,cnt,biggest);
    }


    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int cnt = 0;
        int biggest = INT_MIN;
        func(root,cnt,biggest);
        return cnt;
    }
};