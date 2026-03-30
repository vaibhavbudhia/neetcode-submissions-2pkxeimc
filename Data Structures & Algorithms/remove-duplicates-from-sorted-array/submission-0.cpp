class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;   
        while(i<n-1 && j<n){
            if(nums[i]==nums[j]){
                for(int x = j; x<n; x++){
                    nums[x]=nums[x+1];
                }
                n--;
            }
            else{
                i++;
                j++;
            }
        }
        int k = n;
        return k;
    }
};