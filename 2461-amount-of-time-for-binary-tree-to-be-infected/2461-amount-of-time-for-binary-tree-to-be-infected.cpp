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

    void findTargetAddress(TreeNode* root, int start ,TreeNode*& target){
            if(root==NULL)return;
            if(root->val == start){
                target = root;
                return ;
            }
            findTargetAddress(root->left,start,target);
            findTargetAddress(root->right,start,target);
        }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode * , TreeNode *>parent;
            queue<TreeNode *>q;
            q.push(root);
            while(!q.empty()){
                TreeNode * node = q.front();
                q.pop();
                if(node->left){
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }

            TreeNode * target = nullptr;
            findTargetAddress(root,start,target) ;
            int time = 0;
            unordered_set<TreeNode *>st;
            st.insert(target);
            q.push(target);
            while(!q.empty()){
                time++;
                int size = q.size();
                for(int i=0;i<size;i++){
                    TreeNode * node = q.front();
                    q.pop();
                    if(node->left && st.find(node->left)==st.end()){
                        st.insert(node->left);
                        q.push(node->left);
                    }
                    if(node->right && st.find(node->right)==st.end()){
                        st.insert(node->right);
                        q.push(node->right);
                    }
                    if(parent.find(node)!=parent.end() && st.find(parent[node])==st.end()){
                        st.insert(parent[node]);
                        q.push(parent[node]);
                    }
                }
                
            }
            return time-1;
    }
};