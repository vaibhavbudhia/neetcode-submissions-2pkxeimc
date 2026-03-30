class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int currMax = arr[n-1];
        int element;
        arr[n-1] = -1;

        for(int i = n-2; i>=0; i--){
            element = arr[i]; 
            arr[i] = currMax;
            currMax = max(currMax, element);
        }
        return arr;
    }
};