class Solution {
public:
    int solve(int i, bool canIbuy, vector<int>& price,
              vector<vector<int>>& dp) {
        if (i >= price.size()) {
            return 0;
        }
        if (dp[i][canIbuy] != -1) {
            return dp[i][canIbuy];
        }

        int profit = 0;
        if (canIbuy) {
            int takeValue = -price[i] + solve(i + 1, !canIbuy, price, dp);
            int notTakeValue = solve(i + 1, canIbuy, price, dp);

            profit = max(takeValue, notTakeValue);
        } else {
            int takeValue = price[i] + solve(i + 1, !canIbuy, price, dp);
            int notTakeValue = solve(i + 1, canIbuy, price, dp);

            profit = max(takeValue, notTakeValue);
        }

        return dp[i][canIbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, true, prices, dp);

        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];

        for (int i = 1; i<n; i++) {
            int buyStock = -prices[i] + dp[i - 1][0];
            int notBuyStock = dp[i - 1][1];

            dp[i][1] = max(buyStock, notBuyStock);

            int sellStock = prices[i] + dp[i - 1][1];
            int notSellStock = dp[i - 1][0];

            dp[i][0] = max(sellStock, notSellStock);
        }

        return dp[n - 1][0];
    }
};