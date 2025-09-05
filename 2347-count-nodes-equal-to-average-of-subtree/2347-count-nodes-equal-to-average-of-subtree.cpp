class Solution {
public:

    pair<int,int> func(TreeNode * root , int & cnt){
        if(!root) return {0,0};

        auto left  = func(root->left, cnt);
        auto right = func(root->right, cnt);

        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        if(root->val == sum / nodes){
            cnt++;
        }

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        func(root,cnt);
        return cnt;
    }
};
