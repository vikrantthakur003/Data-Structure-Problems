class Solution {
public:
    int solve(int i, int amount, vector<int>&arr, vector<vector<int>>&dp){
        if(i == 0){
            if(amount % arr[0] == 0){
                return amount / arr[0];
            }
            return 1e9;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int takeValue = 1e9;
        if(arr[i] <= amount){
            takeValue = 1 + solve(i, amount - arr[i], arr, dp);
        }

        int notTakeValue = solve(i - 1, amount, arr, dp);

        return dp[i][amount] = min(takeValue, notTakeValue);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins, dp);

        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};