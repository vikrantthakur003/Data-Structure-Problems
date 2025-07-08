class Solution {
public:
    int solve(int ind, int amount, vector<int>&arr, vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }

        if(ind == 0){
            if(amount%arr[0] == 0){
                return 1;
            }
            return 0;
        }

        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        int takeCoin = 0;
        if(arr[ind] <= amount){
            takeCoin = solve(ind, amount - arr[ind], arr, dp);
        }

        int skipCoin = solve(ind - 1, amount, arr, dp);

        return dp[ind][amount] = takeCoin + skipCoin;
    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};