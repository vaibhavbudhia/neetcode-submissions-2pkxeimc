class Solution {
public:
    void permute(int index, vector<int>& arr,vector<vector<int>>& ans){
        if(index == arr.size()){
            ans.push_back(arr);
        }

        for(int i = index; i<arr.size(); i++){
            if(i>index && arr[i] == arr[index]) continue;
            swap(arr[index], arr[i]);
            permute(index+1, arr, ans);
        }
        for(int i = arr.size()-1; i>index; i--){
            swap(arr[index], arr[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        permute(0, nums, ans);
        return ans;
    }
};
