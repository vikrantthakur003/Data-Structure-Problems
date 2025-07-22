class Solution {
public:
    int solve(int ind, bool canIBuy, int noOfTimesTransactions, vector<int> & prices, vector<vector<vector<int>>>& dp){
        if(ind >= prices.size()){
            return 0;
        }

        if(noOfTimesTransactions >= 2){
            return 0;
        }

        if(dp[ind][canIBuy][noOfTimesTransactions] != -1){
            return dp[ind][canIBuy][noOfTimesTransactions];
        }

        int profit = 0;
        if(canIBuy && noOfTimesTransactions <= 2){
            int buyValue = -prices[ind] + solve(ind + 1, false, noOfTimesTransactions, prices, dp);
            int skipBuy = solve(ind + 1, true, noOfTimesTransactions, prices, dp);

            profit = max(buyValue, skipBuy);
        } else if(noOfTimesTransactions <=2) {
            int sellValue = prices[ind] + solve(ind + 1, true, noOfTimesTransactions + 1, prices, dp);
            int skipSell = solve(ind + 1, false, noOfTimesTransactions, prices, dp);

            profit = max(sellValue, skipSell);
        }

        return dp[ind][canIBuy][noOfTimesTransactions] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(0, 1, 0, prices, dp);
    }
};