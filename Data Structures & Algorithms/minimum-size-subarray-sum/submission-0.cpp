class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int count = 0;
        int minCount = INT_MAX;
        int sum = 0;

        while(r<nums.size()){
            sum += nums[r];
            count++;

            while(sum>=target){
            minCount = min(minCount, count);
                    sum -= nums[l];
                    count--;
                    l++;
                }
            
            r++;
        }
            if(minCount == INT_MAX) return 0;
            return minCount;
    }
};