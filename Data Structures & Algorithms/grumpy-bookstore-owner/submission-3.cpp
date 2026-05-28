class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0;
        int sum = 0;
        int maxSum = 0;
        for(int r = 0; r<customers.size(); r++){
            
            if(grumpy[r]==1)
            sum += customers[r];

            while(r-l+1>minutes){
                if(grumpy[l]==1) sum-=customers[l];
                l++;
            }             
        
            maxSum = max(maxSum,sum);
        }
        for(int i = 0; i<customers.size(); i++){
            if(grumpy[i]==0)
            maxSum += customers[i];
        }
return maxSum;
    }
};