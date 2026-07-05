/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    void dfs(Node* node, int depth, unordered_map<int, Node*>& mp){
        if(!node) return;

        if(mp.find(depth) == mp.end()) mp[depth] = node;

        else {
            mp[depth]->next = node;
            mp[depth] = node;
        }
        
        dfs(node->left, depth+1, mp);
        dfs(node->right, depth+1, mp);
    }

    Node* connect(Node* root) {
        unordered_map<int, Node*> mp;
        dfs(root, 0, mp);
        return root;
    }
};