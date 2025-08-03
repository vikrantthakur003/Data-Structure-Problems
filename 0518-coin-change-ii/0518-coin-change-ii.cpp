class Solution {
public:
    int solve(int i, int amount, vector<int>& arr, vector<vector<int>>&dp){
        if(amount <= 0){
            return 1;
        }
        if(i == 0){
            if(amount%arr[0] == 0){
                return 1;
            }
            return 0;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        
        int takeValue = 0;
        if(arr[i] <= amount){
            takeValue = solve(i, amount - arr[i], arr, dp);
        }
        int notTakeValue = solve(i - 1, amount, arr, dp);

        return dp[i][amount] = takeValue + notTakeValue;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};