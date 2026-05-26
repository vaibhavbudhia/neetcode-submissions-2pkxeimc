class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        int l = 0;
        
        for(int r = 1; r<nums.size(); r++){

        while(r-l>k){
            l++;
        }

        for(int i = l; i<r;i++){
                if(nums[i]==nums[r]){
                    return true;
                }
            }
        }
        return false;
    }
};

        