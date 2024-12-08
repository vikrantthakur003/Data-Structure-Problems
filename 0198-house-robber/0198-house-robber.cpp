class Solution {
public:
    int recursion(int n,vector<int>&nums){
        if(n==0){
            return nums[0];
        }
        if(n<0){
            return 0;
        }
        int included = recursion(n-2, nums) + nums[n];
        int excluded = recursion(n-1,nums);

        return max(included, excluded);
    }

    int memo(int n,vector<int>&nums, vector<int>&dp){
        if(n == 0){
            return nums[0];
        }
        if(n<0) return 0;

        if(dp[n] != -1){
            return dp[n];
        }

        int included = memo(n-2, nums, dp) + nums[n];
        int excluded = memo(n-1, nums, dp);

        return dp[n] = max(included, excluded);
    }

    int tabulation(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n, 0);
        if(n==1){
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int included = dp[i-2] + nums[i];
            int excluded = dp[i-1];

            dp[i] = max(included, excluded);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return recursion(n-1, nums);
        vector<int>dp(n, -1);
        return memo(n-1, nums, dp);
        // return tabulation(nums);
    }
};