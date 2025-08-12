class Solution {
public:
    int solve(int i, bool canIbuy, vector<int> &price, vector<vector<int>> &dp){
        if(i >= price.size()){
            return 0;
        }
        if(dp[i][canIbuy] != -1){
            return dp[i][canIbuy];
        }
        
        int profit = 0;
        if(canIbuy){
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
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, true, prices, dp);
    }
};