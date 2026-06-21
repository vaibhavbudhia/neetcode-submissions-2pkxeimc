class Solution {
public:
    void noDup(int idx, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans){
        if(idx == arr.size()){
        if(find(ans.begin(), ans.end(), ds) == ans.end()) ans.push_back(ds);
            return;
            
        }

        // for(int i = 0; i<arr.size(); i++){
            // if(arr[idx] == arr[idx-1]) 
            // noDup(idx+1, arr, ds, ans);            
                ds.push_back(arr[idx]);
                noDup(idx+1, arr, ds, ans);
                ds.pop_back();
                noDup(idx+1, arr, ds, ans);
                   
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        noDup(0, nums, ds, ans);
        return ans;
    }
};
