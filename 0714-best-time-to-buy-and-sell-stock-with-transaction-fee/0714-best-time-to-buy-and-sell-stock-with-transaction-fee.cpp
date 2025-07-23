class Solution {
public:
    int solve(int ind, bool canIbuy, int fee, vector<int> &prices, vector<vector<int>> &dp){
        if(ind >= prices.size()){
            return 0;
        }

        if(dp[ind][canIbuy] != -1){
            return dp[ind][canIbuy];
        }

        int profit = 0;
        if(canIbuy){
            int buyValue = -prices[ind] + solve(ind + 1, false, fee, prices, dp);
            int skipValue = solve(ind + 1, true, fee, prices, dp);

            profit = max(buyValue, skipValue);
        } else {
            int sellValue = prices[ind] - fee + solve(ind + 1, true, fee, prices, dp);
            int skipSell = solve(ind + 1, false, fee, prices, dp);

            profit = max(sellValue, skipSell);
        }

        return dp[ind][canIbuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>>dp(n, vector<int>(2, -1));
        // return solve(0, 1, fee, prices, dp);

        vector<vector<int>>dp(n, vector<int>(2, 0));

        dp[0][1] = -prices[0];

        for(int i=1; i<n; i++){
            int buyValue = -prices[i] + dp[i - 1][0];
            int skipBuy = dp[i - 1][1];

            dp[i][1] = max(buyValue, skipBuy);

            int sellValue = prices[i] - fee + dp[i - 1][1];
            int skipSell = dp[i - 1][0];

            dp[i][0] = max(sellValue, skipSell);
        }

        return dp[n - 1][0];
    }
};