/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *>mp;
        queue<TreeNode *>q;
        q.push(root);
        mp[root] = NULL;
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right] = node;            
            }
        }
        set<TreeNode *>vis;
        q.push(target);
        vis.insert(target);
        vector<int>ans;
        while(!q.empty()){
            int size = q.size();
            if(k==0){
                for(int i=0;i<size;i++){
                    auto node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                break;
            }
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis.count(node->left)){
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    vis.insert(node->right);
                    q.push(node->right);
                }
                if(mp[node] && !vis.count(mp[node])){
                    vis.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            k--;
        }

        return ans;
    }
};