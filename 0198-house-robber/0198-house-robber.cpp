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
        int n = nums.size();
        // vector<int> dp(nums.size(), -1);
        // return solve(0, nums, dp);

        if(nums.size() == 1){
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for(int i = 2; i<n; i++){
            int takeHouse = nums[i] + dp[i - 2];
            int skipHouse = dp[i - 1];

            dp[i] = max(takeHouse, skipHouse);
        }

        return dp[n - 1];
    }
};