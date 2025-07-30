class Solution {
public:
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp) {
        if (ind >= nums.size()) {
            if (target == 0) {
                return true;
            }
            return false;
        }

        if (target == 0) {
            return true;
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        int takeValue = false;
        if (nums[ind] <= target) {
            takeValue = solve(ind + 1, target - nums[ind], nums, dp);
        }
        int notTakeValue = solve(ind + 1, target, nums, dp);

        return dp[ind][target] = takeValue || notTakeValue;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        int targetSum = sum / 2;
        vector<vector<int>>dp(n, vector<int>(targetSum + 1, -1));
        return solve(0, targetSum, nums, dp);
    }
};