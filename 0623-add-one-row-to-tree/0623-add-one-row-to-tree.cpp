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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        queue<TreeNode*>q;
        q.push(root);
        int dep = 1;
        while(!q.empty()){
            int size = q.size();
            if(depth - 1 == dep){
                for(int i=0;i<size;i++){
                    TreeNode * node = q.front();
                    q.pop();
                    TreeNode * tmp1 = new TreeNode(val);
                    TreeNode * tmp2 = new TreeNode(val);
                    tmp1->left = node->left;
                    tmp2->right = node->right;
                    node->left = tmp1;
                    node->right = tmp2;
                }
                return root;
            }
            for(int i=0;i<size;i++){
                TreeNode * node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            dep++;
        }
        return root;
    }
};