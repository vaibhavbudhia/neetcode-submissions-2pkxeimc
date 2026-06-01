class Solution {
public: 
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxCount = 0;
        
        for(int r = nums.size()-1; r>0; r--){
            int l = r-1;
            int count = 0;
            int rem = k;

            while(l>=0){
                if(rem>0){
                int diff = nums[r] - nums[l];
                rem = rem - diff;
                if(rem >=0) count++;
                }
                l--;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount+1;
    }
};