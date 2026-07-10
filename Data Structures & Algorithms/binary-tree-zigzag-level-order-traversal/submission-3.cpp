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
    void dfs(TreeNode* node,int depth, vector<int>&ds, vector<vector<int>>&ans){
        if(!node) return;

        if(ans.size() == depth){
            ans.push_back({});
        }

        ans[depth].push_back(node->val);

        dfs(node->left, depth+1, ds, ans);
        dfs(node->right, depth+1, ds, ans);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int depth = 0;
        vector<int> ds;
        vector<vector<int>> ans;
        dfs(root, 0, ds, ans);

        for(int i = 0; i<ans.size(); i++){
            if(i & 1){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};