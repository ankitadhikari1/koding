class Solution {
public:
    TreeNode* buildTreeHelper(
        vector<int>& inorder, int inStart, int inEnd,
        vector<int>& postorder, int postStart, int postEnd,
        unordered_map<int,int>& mp
    ) {
        if (inStart > inEnd || postStart > postEnd) return NULL;

        
        int rootElement = postorder[postEnd];
        TreeNode* root = new TreeNode(rootElement);

        int idx = mp[rootElement]; 
        int leftSize = idx - inStart;

        
        root->left = buildTreeHelper(inorder, inStart, idx - 1,postorder, postStart, postStart + leftSize - 1, mp);

        
        root->right = buildTreeHelper(inorder, idx + 1, inEnd,postorder, postStart + leftSize, postEnd - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }
};
