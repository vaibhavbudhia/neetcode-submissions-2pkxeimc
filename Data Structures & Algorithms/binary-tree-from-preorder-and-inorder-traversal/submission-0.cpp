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
    TreeNode* Tree(int preStart, int preEnd, vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart; 

        root->left = Tree(preStart + 1, preStart + numsLeft, preorder, inorder,  inStart, inRoot-1, inMap);
        root->right = Tree(preStart + numsLeft + 1, preEnd, preorder, inorder,  inRoot+1, inEnd, inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int i = 0;
        while(i<inorder.size()){
            inMap[inorder[i]] = i;
            i++;
        }        
        TreeNode* root = Tree(0, preorder.size()-1, preorder, inorder, 0, inorder.size()-1, inMap);
        
        return root;
    }
};
