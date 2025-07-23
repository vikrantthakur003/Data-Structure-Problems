class Solution {
public:
    int solve(int ind, bool canIbuy, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (ind >= prices.size()) {
            return 0;
        }

        if (dp[ind][canIbuy] != -1) {
            return dp[ind][canIbuy];
        }

        int profit = 0;
        if (canIbuy) {
            int buyValue = -prices[ind] + solve(ind + 1, false, prices, dp);
            int skipBuy = solve(ind + 1, true, prices, dp);

            profit = max(buyValue, skipBuy);
        } else {
            int sellValue = prices[ind] + solve(ind + 2, true, prices, dp);
            int skipValue = solve(ind + 1, false, prices, dp);

            profit = max(sellValue, skipValue);
        }

        return dp[ind][canIbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n, vector<int>(2, -1));
        // return solve(0, 1, prices, dp);

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            if (i >= 2) {
                int buyValue = -prices[i] + dp[i - 2][0];
                int skipBuy = dp[i - 1][1];

                dp[i][1] = max(buyValue, skipBuy);
            } else {
                dp[i][1] = max(-prices[i], dp[i - 1][1]);
            }
            int sellValue = prices[i] + dp[i - 1][1];
            int skipSell = dp[i - 1][0];

            dp[i][0] = max(sellValue, skipSell);
        }

        return dp[n - 1][0];
    }
};