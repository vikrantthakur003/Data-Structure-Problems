class Solution {
public:
    int solve(int index, int lastIndex, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index][lastIndex + 1] != -1) {
            return dp[index][lastIndex + 1];
        }

        int takeValue = 0;
        if (lastIndex == -1 || nums[index] > nums[lastIndex]) {
            takeValue = 1 + solve(index + 1, index, nums, dp);
        }

        int notTakeValue = solve(index + 1, lastIndex, nums, dp);
        return dp[index][lastIndex + 1] = max(takeValue, notTakeValue);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return solve(0, -1, nums, dp);

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j = n; j >= 0; j--) {

        //         int takeValue = 0;
        //         if (nums[i] > nums[j - 1]) {
        //             takeValue = 1 + dp[i + 1][i];
        //         }
        //         int notTakeValue = dp[i + 1][j];

        //         dp[i][j] = max(takeValue, notTakeValue);
        //     }
        // }

        // return dp[0][0];

        vector<int>dp(n, 1);
        for(int i = 0; i<n; i++){
            for(int lastIndex = 0; lastIndex <n; lastIndex++){
                if(nums[i] > nums[lastIndex]){
                    dp[i] = max(dp[i], 1 + dp[lastIndex]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};