class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0;

        while (i < numbers.size()-1) {
        int j = i+1;
            while(j < numbers.size()){
                
                if(numbers[i] + numbers[j] != target){
                    j++;
                }
                
                if(numbers[i] + numbers[j] == target){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    break;
                }
            }
            if(numbers[i] + numbers[j] == target) break;
            i++;
        }
    return ans;
    }
};
