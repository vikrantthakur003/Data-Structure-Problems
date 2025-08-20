class Solution {
public:
    int solve(int index, int lastIndex, vector<int>&nums, vector<vector<int>>&dp){
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index][lastIndex + 1] != -1){
            return dp[index][lastIndex + 1];
        }

        int takeValue = 0;
        if(lastIndex == -1 || nums[index] > nums[lastIndex]){
            takeValue = 1 + solve(index + 1, index, nums, dp);
        } 

        int notTakeValue = solve(index + 1, lastIndex, nums, dp);
        return dp[index][lastIndex + 1] = max(takeValue, notTakeValue);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, -1, nums, dp);
    }
};