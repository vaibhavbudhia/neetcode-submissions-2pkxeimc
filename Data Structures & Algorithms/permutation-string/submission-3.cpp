class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length()) return false;
        string s3 = s1;
        
        for(int r = 0; r<=s2.length() - s1.length(); r++){
            s3 = s1;
            for(int i = r; i<r+s1.length(); i++){
                size_t pos = s3.find(s2[i]);
                if (pos != string::npos) s3.erase(pos, 1);
                else break;
            }
            if(s3.empty()) return true;
        }
    return false;
    }
};