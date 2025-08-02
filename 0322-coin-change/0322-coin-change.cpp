class Solution {
public:
    int solve(int i, int amount, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % arr[0] == 0) {
                return amount / arr[0];
            }
            return 1e9;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int takeValue = 1e9;
        if (arr[i] <= amount) {
            takeValue = 1 + solve(i, amount - arr[i], arr, dp);
        }

        int notTakeValue = solve(i - 1, amount, arr, dp);

        return dp[i][amount] = min(takeValue, notTakeValue);
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int takeValue = 1e9;
                if (coins[i] <= j) {
                    takeValue = dp[i][j - coins[i]] + 1;
                }
                int notTakeValue = dp[i - 1][j];

                dp[i][j] = min(takeValue, notTakeValue);
            }
        }

        return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
    }
};