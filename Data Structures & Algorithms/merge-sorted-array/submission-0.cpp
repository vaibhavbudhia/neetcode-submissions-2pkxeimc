class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;

        while(i<m && j<n){
            if(nums1[i]<=nums2[j])
                i++;

            else if(nums1[i]>nums2[j]){
                int k = m;
            
                while(k>i){
                nums1[k] = nums1[k-1];
                k--;
                }
            
                nums1[i] = nums2[j];
            
                i++;
                j++;
                m++;
            }
        }
    
    while(j<n){
        nums1[i] = nums2[j];
        i++;
        j++;
    }
    }
};