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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
    
        queue<pair<TreeNode *,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode * node = it.first;
            int row = it.second.first;
            int col = it.second.second;
            mp[col].push_back({row,node->val});
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }

        for(auto & it : mp){
            auto & arr = it.second;
            sort(arr.begin(),arr.end(),[](auto & a,auto & b){
                if(a.first==b.first){
                    return a.second<b.second;
                }

                return a.first<b.first;
            });
        }

        vector<vector<int>>ans;
        for(auto & it : mp){
            vector<int>temp;
            for(auto & itr : it.second){
                temp.push_back(itr.second);
            }
            ans.push_back(temp);
            
        }

        return ans;
    }
};