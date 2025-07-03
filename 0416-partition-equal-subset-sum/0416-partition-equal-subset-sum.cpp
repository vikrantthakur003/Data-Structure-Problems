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
        // vector<vector<int>> dp(nums.size(), vector<int>(targetSum + 1, -1));
        // return solve(0, nums, targetSum, dp);

        vector<vector<bool>> dp(nums.size(), vector<bool>(targetSum + 1, false));

        // if n > 0 but targetSum == 0 then avery row have true value
        for(int i=0;i<nums.size();i++){
            dp[i][0] = true;
        }

        if(nums[0] <= targetSum){
            dp[0][nums[0]] = true;
        }

        for(int i=1;i<nums.size();i++){
            for(int target = 1; target <= targetSum; target++){
                bool notTakeValue = dp[i - 1][target];
                bool takeValue = false;

                if(nums[i] <= target){
                    takeValue = dp[i - 1][target - nums[i]];
                }

                dp[i][target] = notTakeValue || takeValue;
            }
        }

        return dp[nums.size() - 1][targetSum];
    }
};