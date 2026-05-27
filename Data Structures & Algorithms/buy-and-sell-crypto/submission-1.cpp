class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l = 0;
        int r = 1;

        int maxProfit = 0;

        while(r < prices.size()) {

            // profitable transaction
            if(prices[r] > prices[l]) {
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);
            }
            else {
                // found smaller buying price
                l = r;
            }

            r++;
        }

        return maxProfit;
    }
};