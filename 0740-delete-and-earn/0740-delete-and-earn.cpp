class Solution {
public:
    int solve(int i, vector<int>&nums, vector<int>&dp){
        if(i >= nums.size()){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }

        int takeValue = nums[i] + solve(i + 2, nums, dp);

        int notTakeValue = solve(i + 1, nums, dp);

        return dp[i] = max(takeValue, notTakeValue);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> points(maxNum + 1, 0);

        for (int num : nums) {
            points[num] += num;
        }
        
        // vector<int>dp(maxNum + 1, -1);
        // return solve(0, points, dp);

        vector<int>dp(maxNum + 1, 0);
        dp[0] = 0;
        dp[1] = max(points[0], points[1]);
        for(int i = 2; i<=maxNum; i++){
            int takeValue = points[i] + dp[i - 2];
            int notTakeValue = dp[i - 1];

            dp[i] = max(takeValue, notTakeValue);
        }

        return dp[maxNum];
    }
};