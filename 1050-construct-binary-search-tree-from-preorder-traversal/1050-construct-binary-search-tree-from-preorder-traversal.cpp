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

    TreeNode * buildTree(vector<int>&preorder,int start,int end){
        if(start>end)return NULL;
        TreeNode * root = new TreeNode(preorder[start]);
        int n2Start = end+1 ;
        for(int i=start+1;i<=end;i++){
            if(preorder[i]>preorder[start]){
                n2Start = i;
                break;
            }
        }
        root->left = buildTree(preorder,start+1,n2Start-1);
        root->right = buildTree(preorder,n2Start,end);
        return root;
    }



    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int preStart = 0;
        int preEnd = n-1;
        TreeNode * root = buildTree(preorder,preStart,preEnd);
        return root;
    }
};