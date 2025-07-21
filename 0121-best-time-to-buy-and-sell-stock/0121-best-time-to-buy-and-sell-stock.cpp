class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int buyStock = prices[0];

        for(int i=1;i<prices.size(); i++){
            int profit = prices[i] - buyStock;

            if(maximumProfit < profit){
                maximumProfit = profit;
            }

            buyStock = min(buyStock, prices[i]);
        }

        return maximumProfit;
    }
};