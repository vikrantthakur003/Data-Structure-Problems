class Solution {
public:
    int solve(int ind, int currentTarget, vector<int>&arr, int target, int n){
        if(ind >= n){
            return currentTarget == target;
        }

        int takePlusSign = solve(ind + 1, currentTarget + arr[ind], arr, target, n);
        int takeSubstractSign = solve(ind + 1, currentTarget - arr[ind], arr, target, n);

        return takeSubstractSign + takePlusSign;
    }

    int getSubsetS1(int ind, vector<int>&nums, int target, vector<vector<int>>&dp){
        if(ind == 0){
            if(target == 0 && nums[0] == 0){
                return 2;
            } else if(target == 0 || nums[0] == target){
                return 1;
            } 
            return 0;
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        int takeValue = 0;
        if(nums[ind] <= target){
            takeValue = getSubsetS1(ind - 1, nums, target - nums[ind], dp);
        }

        int notTakeValue = getSubsetS1(ind - 1, nums, target, dp);

        return dp[ind][target] = takeValue + notTakeValue;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // return solve(0, 0, nums, target, n);

        // approach like partition with difference
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        if((totalSum - target) < 0){
            return 0;
        } else if((totalSum - target)%2 == 1){
            return 0;
        }

        int targetValue = (totalSum - target)/2;
        vector<vector<int>> dp(n, vector<int>(targetValue + 1, -1));
        return getSubsetS1( n - 1, nums, targetValue, dp);
    }
};