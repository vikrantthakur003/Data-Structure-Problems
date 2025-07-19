class Solution {
public:
    int solve(int index, vector<int> & nums, vector<int> & dp){
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int takeHouse = nums[index] + solve(index + 2, nums, dp);
        int skipHouse = solve(index + 1, nums, dp);

        return dp[index] =  max(takeHouse, skipHouse);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};