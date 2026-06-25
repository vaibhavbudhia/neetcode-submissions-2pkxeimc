class Solution {
public:

    void partition(int index, string& s, vector<string>& ans, int parts){
        if(parts == 4){
            if(index == s.size()){
                ans.push_back(s);
            }
            return;
        }

        for(int i = index; i<min(index+3, (int)s.size()); i++){
            if(isIP(s, index, i)){
                if(parts == 3) 
                partition(i+1, s, ans, parts+1);
                //add "."
                else{
                    s.insert(i+1, 1, '.');
                    partition(i+2, s, ans, parts+1);
                    s.erase(i+1, 1);
                }
            }
        }
    }

    bool isIP(string s, int start, int end){
        if (end - start + 1 > 3)
            return false;

        if (s[start] == '0' && start != end)
            return false;

        string substr = s.substr(start, end - start + 1);
        int num = stoi(substr);
        if(num >= 0 && num <=255) return true;
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        partition(0, s, ans, 0);
        return ans;
    }
};