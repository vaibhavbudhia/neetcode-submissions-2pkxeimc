class Solution {
public:

    unordered_map<char,string> keypad = {
        {'2' , "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv"},
        {'9' , "wxyz"}
    };

    void allComb(string& s, string& digits,int index, vector<string>& ans){
        if (digits.empty()) return;

        if(index == digits.size()){
            ans.push_back(s);
            return;
        }

        for(const char& c : keypad[digits[index]]){
        s.push_back(c);
        allComb(s, digits, index+1, ans);
        s.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s = "";
        allComb(s, digits, 0, ans);
        return ans;
    }
};
