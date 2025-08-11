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


    TreeNode * buildTreeHelper(vector<int>&inorder,vector<int>&preorder,unordered_map<int,int>&mp,int inStart,int inEnd,int preStart,int preEnd){
        if(inStart > inEnd || preStart > preEnd)return NULL;

        int rootElement = preorder[preStart];
        int idx = mp[rootElement];
        int elementCount = idx - inStart;

        TreeNode * root = new TreeNode(rootElement);

        root->left = buildTreeHelper(inorder,preorder,mp,inStart,idx-1,preStart+1,preStart+elementCount);
        root->right = buildTreeHelper(inorder,preorder,mp,idx+1,inEnd,preStart+elementCount+1,preEnd);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode * root = buildTreeHelper(inorder,preorder,mp,0,n-1,0,n-1);
        return root;
    }
};