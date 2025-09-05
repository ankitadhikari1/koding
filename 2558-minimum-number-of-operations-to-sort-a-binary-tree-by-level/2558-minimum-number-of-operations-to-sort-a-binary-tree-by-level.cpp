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
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;   
        queue<TreeNode *>q;
        q.push(root);
        int total = 0;
        while(!q.empty()){
            int n = q.size();
            unordered_map<int,int>mp;
            vector<int>arr;
            int cnt = 0;
            for(int i=0;i<n;i++){
                auto node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                arr.push_back(node->val);
                mp[node->val] = i;
            }
            vector<int>sortedArr = arr;
            sort(sortedArr.begin(),sortedArr.end());
            for(int i=0;i<n;i++){
                if(arr[i]!=sortedArr[i]){
                    int ind = mp[sortedArr[i]];
                    swap(arr[i],arr[ind]);
                    cnt++;
                    mp[arr[ind]] = ind;
                    mp[arr[i]] = i;
                }
            }
            total+=cnt;
        }
        return total;
    }
};