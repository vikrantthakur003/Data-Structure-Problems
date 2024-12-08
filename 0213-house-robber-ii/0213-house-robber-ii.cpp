class Solution {
public:
    int recursion(int start, int end, vector<int>&nums){
        if(start > end){
            return 0;
        }
        int included = recursion(start+2, end, nums) + nums[start];
        int excluded = recursion(start+1,end, nums);

        return max(included, excluded);
    }

    int memo(int start, int end, vector<int>&nums, vector<int>&dp){
        if(start > end){
            return 0;
        }

        if(dp[start] != -1){
            return dp[start];
        }

        int included = memo(start+2, end, nums,dp) + nums[start];
        int excluded = memo(start+1, end, nums,dp);

        return dp[start] = max(included, excluded);
    }
    int tabulation(int start, int end, vector<int>&nums){
        int n = end-start+1;
        vector<int>dp(n, 0);
        dp[0] = nums[start];
        if (n > 1) dp[1] = max(nums[start], nums[start + 1]);

        for(int i=2;i<n; i++){
            int included = dp[i-2] + nums[start+i];
            int excluded = dp[i-1];

            dp[i] = max(included, excluded);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        // vector<int>dp1(n, -1);
        // vector<int>dp2(n, -1);

        // int firstValueTake = recursion(0, n-2, nums);
        // int lastValueTaks = recursion(1, n-1, nums);

        // int firstValueTake = memo(0, n-2, nums, dp1);
        // int lastValueTaks = memo(1, n-1, nums, dp2);

        int firstValueTake = tabulation(0, n-2, nums);
        int lastValueTaks = tabulation(1, n-1, nums);
        return max(firstValueTake, lastValueTaks);
    }
};