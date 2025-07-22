class Solution {
public:
    int solve(int ind, bool canIBuy, int noOfTimesBuy, vector<int> & prices, vector<vector<vector<int>>>& dp){
        if(ind >= prices.size()){
            return 0;
        }

        if(noOfTimesBuy > 2){
            return 0;
        }

        if(dp[ind][canIBuy][noOfTimesBuy] != -1){
            return dp[ind][canIBuy][noOfTimesBuy];
        }

        int profit = 0;
        if(canIBuy && noOfTimesBuy <= 2){
            int buyValue = -prices[ind] + solve(ind + 1, false, noOfTimesBuy + 1, prices, dp);
            int skipBuy = solve(ind + 1, true, noOfTimesBuy, prices, dp);

            profit = max(buyValue, skipBuy);
        } else if(noOfTimesBuy <=2 ) {
            int sellValue = prices[ind] + solve(ind + 1, true, noOfTimesBuy, prices, dp);
            int skipSell = solve(ind + 1, false, noOfTimesBuy, prices, dp);

            profit = max(sellValue, skipSell);
        }

        return dp[ind][canIBuy][noOfTimesBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 0, prices, dp);
    }
};