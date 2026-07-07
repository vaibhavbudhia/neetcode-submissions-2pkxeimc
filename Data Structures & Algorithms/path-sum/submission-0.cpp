/**
 * Definition for a binary tree root.
 * struct Treeroot {
 *     int val;
 *     Treeroot *left;
 *     Treeroot *right;
 *     Treeroot() : val(0), left(nullptr), right(nullptr) {}
 *     Treeroot(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Treeroot(int x, Treeroot *left, Treeroot *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        targetSum -= root->val;

        bool l = hasPathSum(root->left, targetSum);
        bool r = hasPathSum(root->right, targetSum);

        if(!root->left && !root->right) return targetSum ==0;
        
        return l||r;
    }
};