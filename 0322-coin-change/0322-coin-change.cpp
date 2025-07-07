class Solution {
public:
    int solve(int ind, vector<int>&coins, int amount, vector<vector<int>> &dp){
        if(amount <= 0){
            return 0;
        }

        if(ind == 0){ 
           if(amount % coins[0] == 0){
                return amount / coins[0]; 
           }
            return 1e9;
        }

        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        int takeCoin = INT_MAX;
        int skipCoin = solve(ind - 1, coins, amount, dp);

        if(coins[ind] <= amount) {
            takeCoin = 1 + solve(ind, coins, amount - coins[ind], dp);
        }

        return dp[ind][amount] = min(takeCoin, skipCoin);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n - 1, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};