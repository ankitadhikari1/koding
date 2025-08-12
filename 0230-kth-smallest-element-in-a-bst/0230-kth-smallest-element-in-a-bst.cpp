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

    void inorder(TreeNode * root , int &k , int & kthelement){
        if(!root)return ;
        
        inorder(root->left,k,kthelement);
        k--;
        if(k==0){kthelement=root->val;return;};
        inorder(root->right,k,kthelement);
        
    }

    int kthSmallest(TreeNode* root, int k) {
       
        int kSmallCopy = k;
        
        
		int kthSmallest = -1;
        inorder(root,kSmallCopy,kthSmallest);

		

        return kthSmallest;
        
    }
};