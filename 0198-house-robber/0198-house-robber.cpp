class Solution {
public:
    // int solveUsingRecursion(vector<int>&nums, int n){
    //     if(n == 0){
    //         return nums[0];
    //     }
    //     if(n < 0){
    //         return 0;
    //     }

    //     int inclaudeCurrentElement = solveUsingRecursion(nums, n-2) + nums[n];
    //     int exclaudeCurrentElement = solveUsingRecursion(nums, n-1) + 0;

    //     return max(inclaudeCurrentElement,exclaudeCurrentElement);
    // }

    int solveUsingMemo(vector<int>&nums, int n, vector<int>&dp){
        if(n == 0){
            return nums[0];
        }
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int inclaudeCurrentElement = solveUsingMemo(nums, n-2,dp) + nums[n];
        int exclaudeCurrentElement = solveUsingMemo(nums, n-1,dp) + 0;

        return dp[n] = max(inclaudeCurrentElement,exclaudeCurrentElement);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solveUsingRecursion(nums, n-1);
        vector<int>dp(n, -1);
        return solveUsingMemo(nums, n-1, dp);
    }
};