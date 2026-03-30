class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
            int size = nums.size();
            int ansSize = 2*size;
            vector<int> ans(ansSize);
            for (int i = 0; i<ansSize; i++){
                if(i<size){
                    ans[i]=nums[i];
                }
                else{
                    ans[i]=nums[i - size];
                }
            }
    return ans;
    }
};