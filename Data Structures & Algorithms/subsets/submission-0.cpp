class Solution {
public:
        void findSubsets(int idx, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans){
            if(idx==arr.size()){
                ans.push_back(ds);
                // for(auto it: ds) {cout << it << " " <<endl;
                    return;
                
            }

            ds.push_back(arr[idx]);
            findSubsets(idx+1, arr, ds, ans);
            ds.pop_back();
            findSubsets(idx+1, arr, ds, ans);
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};
