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
    bool bst = true;
    stack<int> ans;

    void dfs(TreeNode* root){
        if(!root) return;
        
        dfs(root->left);
        if (!ans.empty() && ans.top() >= root->val)
        bst = false;
        ans.push(root->val);
        dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        dfs(root);
        return bst;
    }
};
