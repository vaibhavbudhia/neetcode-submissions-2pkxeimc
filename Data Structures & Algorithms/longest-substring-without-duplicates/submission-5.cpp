class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxCount = 0;
        // int count = 0;
        string subs = "";

        for(int r = 0; r<s.length(); r++){
            
            int pos = subs.find(s[r]);
            subs += s[r];

            // if(pos == string::npos){
            // count++;
            // }
            
            if(pos != string::npos){
                for(int i = 0; i<=pos; i++){
                    subs.erase(0,1);
                    l++;
                    // count--;
                }
            }
            
            int subsLength = subs.length();
        maxCount =  max(maxCount,subsLength);
        }

        return maxCount;
    }
};
