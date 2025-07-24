class Solution {
public:
    int solve(int ind, int lastIndex, vector<int> & arr, vector<vector<int>> &dp){
        if(ind >= arr.size()){
            return 0;
        }

        if(dp[ind][lastIndex + 1] != -1){
            return dp[ind][lastIndex + 1];
        }

        int takeValue = 0;
        if(lastIndex == -1 || arr[ind] > arr[lastIndex]){
            takeValue = 1 + solve(ind + 1, ind, arr, dp);
        }

        int notTakeValue = solve(ind + 1, lastIndex, arr, dp);

        return dp[ind][lastIndex + 1] = max(takeValue, notTakeValue);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve(0, -1, nums, dp);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int lastIndex = i - 1; lastIndex >= -1; lastIndex--){
                int takeValue = 0;
                if(lastIndex == -1 || nums[i] > nums[lastIndex]){
                    takeValue = 1 + dp[i + 1][i + 1];
                }
                int notTakeValue = dp[i + 1][lastIndex + 1];

                dp[i][lastIndex + 1] = max(takeValue, notTakeValue);
            }
        }
        return dp[0][0];

    }
};