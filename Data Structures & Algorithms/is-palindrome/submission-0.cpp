class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;

        for(char c : s){
            if(isalnum(c))
                cleaned += tolower(c);
        }

        int n = cleaned.size();
        int i =0;
        int j = n-1;
        
        while(i<j){
            if(cleaned[i] != cleaned[j])
            return false;
            i++;
            j--;
    }
            return true;
    }
};