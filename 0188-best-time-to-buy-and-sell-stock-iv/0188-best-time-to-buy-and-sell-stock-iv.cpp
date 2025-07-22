class Solution {
public:
    int solve(int ind, bool canIbuy, int k, vector<int> & prices, vector<vector<vector<int>>> &dp){
        if(ind >= prices.size()){
            return 0;
        }

        if(k <= 0){
            return 0;
        }

        if(dp[ind][canIbuy][k] != -1){
            return dp[ind][canIbuy][k];
        }

        int profit = 0;
        if(canIbuy && k > 0){
            int buyValue = -prices[ind] + solve(ind + 1, false, k, prices, dp);
            int skipBuy = solve(ind + 1, true, k, prices, dp);

            profit = max(buyValue, skipBuy);
        } else if(k > 0) {
            int sellValue = prices[ind] + solve(ind + 1, true, k - 1, prices, dp);
            int skipSell = solve(ind + 1, false, k, prices, dp);

            profit = max(sellValue, skipSell);
        }

        return dp[ind][canIbuy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};