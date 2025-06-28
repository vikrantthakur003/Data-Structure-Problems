class Solution {
public:
    int houseRobber(int index, vector<int> & nums, vector<int> &dp){
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int takeValue = nums[index]  + houseRobber(index + 2, nums, dp);
        int notTakeValue = houseRobber(index + 1, nums, dp);

        return dp[index] = max(takeValue, notTakeValue);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return houseRobber(0, nums, dp);

        // return dp[n - 1];
    }
};