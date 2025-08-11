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
    int findLeftHeight(TreeNode * node){
        if(node==NULL)return 0;
        int cnt = 0;
        while(node){
            cnt++;
            node=node->left;
        }
        return cnt;
    }
    int findRightHeight(TreeNode * node){
        if(node==NULL)return 0;
        int cnt = 0;
        while(node){
            cnt++;
            node=node->right;
        }
        return cnt;
    }


    int countNodes(TreeNode* root) { 
        if(root==nullptr)return 0;

        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        if(leftHeight==rightHeight)return (1<<leftHeight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);

    }
};