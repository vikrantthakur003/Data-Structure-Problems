class Solution {
public:
    bool solve(int index, vector<int>& nums, int target, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(index == nums.size()){
            return target == 0;
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool takeValue = false;
        if(nums[index] <= target){
            takeValue = solve(index + 1, nums, target - nums[index], dp);
        }
        
        bool notTakeValue = solve(index + 1, nums, target, dp);

        return dp[index][target] = takeValue || notTakeValue;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
        }

        if(totalSum%2 != 0){
            return false;
        }
        int targetSum = totalSum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(targetSum + 1, -1));
        return solve(0, nums, targetSum, dp);
    }
};