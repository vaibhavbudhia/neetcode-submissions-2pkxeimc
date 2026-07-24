class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        sort(nums.begin(), nums.end());
        int difference = INT_MAX;
        int minVal = 0;
        int maxVal = 0;
        int l = 0;

        for(int r = 1; r < nums.size(); r++){

            while(r-l+1>k){
                l++;
            }
            minVal = nums[l];
            maxVal = nums[l+k-1];

        // for(int i = l; l<=r;  i++){
        //     maxVal = max(maxVal, nums[i]);
        //     minVal = min(minVal, nums[i]);
        // }
            difference = min(difference, maxVal-minVal);
        }

    return difference;
    }
};