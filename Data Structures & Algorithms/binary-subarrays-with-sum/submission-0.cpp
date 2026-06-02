class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    
        int l = 0;
        int sum  = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            
            for(int r = i; r<nums.size(); r++){
                sum += nums[r];

                if(sum==goal) count++;
            }
        sum = 0;
        }
    return count;
    }

};