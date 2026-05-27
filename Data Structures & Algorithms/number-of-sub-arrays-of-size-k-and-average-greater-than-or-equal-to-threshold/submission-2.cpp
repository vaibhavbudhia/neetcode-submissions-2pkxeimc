class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(k > arr.size()) return 0;
        int l = 0;
        int sum = 0;
        int avg = 0;
        int count = 0;

        for(int r = 0; r<arr.size(); r++){
        
            sum += arr[r];

            while(r-l+1 > k){
            sum -= arr[l];
            l++;
        }

            if((r-l+1)==k){
            avg = sum/k;
            if(avg >=  threshold) count++;
            }
            
       } 
    return count;
    }
};