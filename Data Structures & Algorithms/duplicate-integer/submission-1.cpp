class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool duplicate = false;
        int n = nums.size();
            
            sort(nums.begin(),nums.end());
            for(int i = 1; i<n; i++){
                if (nums[i] == nums[i-1]){
                    duplicate = true;
                    break;
                    }
            }
    return duplicate;
        }
};