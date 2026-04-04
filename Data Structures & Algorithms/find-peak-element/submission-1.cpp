class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int l = 1, r = n-2;
        while(l<=r){
            int k = (l+r)/2;
            if(nums[k]>nums[k+1] && nums[k]>nums[k-1]) return k;
            else if(nums[k]>nums[k-1]) l = k+1;
            else if(nums[k]<nums[k-1]) r = k-1;
        }
        return -1;
    }
};