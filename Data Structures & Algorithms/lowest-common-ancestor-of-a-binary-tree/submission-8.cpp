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

    TreeNode* lca;
    
    pair<bool,bool> dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node || lca) return {false, false};

        auto left = dfs(node->left, p, q);
        auto right = dfs(node->right, p, q);
        bool foundP = left.first || right.first || node == p;
        bool foundQ = left.second || right.second || node == q;

        if(foundP && foundQ && !lca){
            lca = node;
        }

        return {foundP, foundQ};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = NULL;
        dfs(root, p, q);
        return lca;
    }
};