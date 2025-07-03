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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>pq;
        pq.push(root);
        while(!pq.empty()){
            vector<int>temp;
            int n = pq.size();
            for(int i=0;i<n;i++){
                TreeNode * ele = pq.front();
                temp.push_back(ele->val);
                pq.pop();
                if(ele->left!=NULL)pq.push(ele->left);
                if(ele->right!=NULL)pq.push(ele->right);

            }
            ans.push_back(temp);
        }
        return ans;
    }
};