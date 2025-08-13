class Solution {
public:
    int solve(int ind, bool canIBuy, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (ind >= prices.size()) {
            return 0;
        }

        if (dp[ind][canIBuy] != -1) {
            return dp[ind][canIBuy];
        }

        int profit = 0;
        if (canIBuy) {
            int buyValue = -prices[ind] + solve(ind + 1, !canIBuy, prices, dp);
            int notBuyValue = solve(ind + 1, canIBuy, prices, dp);

            profit = max(buyValue, notBuyValue);
        } else {
            int sellValue = prices[ind] + solve(ind + 1, !canIBuy, prices, dp);
            int notSellValue = solve(ind + 1, canIBuy, prices, dp);

            profit = max(sellValue, notSellValue);
        }

        return dp[ind][canIBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return solve(0, true, prices, dp);
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            int buyValue = -prices[i] + dp[i - 1][0];
            int notBuyValue = dp[i - 1][1];

            dp[i][1] = max(buyValue, notBuyValue);
            int sellValue = prices[i] + dp[i - 1][1];
            int notSellValue = dp[i - 1][0];

            dp[i][0] = max(sellValue, notSellValue);
        }

        return dp[n - 1][0];
    }
};