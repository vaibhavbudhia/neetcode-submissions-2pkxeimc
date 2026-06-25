class Solution {
public:
    vector<string> ans;
    
    void parent (int leftP, int rightP,string &s, int n){
        
        if(leftP == n && rightP == n){
        ans.push_back(s);
        return;    
        }

        if(leftP<n){
        s.push_back('(');
        parent(leftP+1,rightP,s,n);
        s.pop_back();
        }

        if (rightP<leftP){
        s.push_back(')');
        parent(leftP,rightP+1,s,n);
        s.pop_back();
        }
    
    }
    vector<string> generateParenthesis(int n) {        
        string s = "";
        parent(0,0,s,n);
        return ans;
    }
};
