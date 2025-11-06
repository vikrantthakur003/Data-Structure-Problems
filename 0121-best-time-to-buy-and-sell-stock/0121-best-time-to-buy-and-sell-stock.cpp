class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        int buyStock = prices[0];
        for(int i = 1; i<prices.size(); i++){

            int profit = prices[i] - buyStock;
            if(profit > maxProfit){
                maxProfit = profit;
            }

            if(prices[i] < buyStock){
                buyStock = prices[i];
            }
        }

        return maxProfit;
    }
};