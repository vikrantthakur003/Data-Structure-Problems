class Solution {
public:
    int houseRobber(int index, vector<int> &nums, int end, vector<int> &dp){
        if(index > end){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int takeValue = nums[index] + houseRobber(index + 2, nums, end, dp);
        int notTakeValue = houseRobber(index + 1, nums, end, dp);
        
        return dp[index] = max(takeValue, notTakeValue);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        if(n == 1){
            return nums[0];
        }
        
        // int firstElementTake = houseRobber(0, nums, n - 2, dp);
        // fill(dp.begin(), dp.end(), -1);
        // int lastElementTake = houseRobber(1, nums, n - 1, dp);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2;i<n-1;i++){
            int takeValue = nums[i] + dp[i-2];
            int notTakeValue = dp[i-1];

            dp[i] = max(takeValue, notTakeValue);
        }

        int firstElementTake = dp[n - 2];

        fill(dp.begin(), dp.end(), -1);
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);

        for(int i=3;i<n;i++){
            int takeValue = nums[i] + dp[i-2];
            int notTakeValue = dp[i-1];

            dp[i] = max(takeValue, notTakeValue);
        }

        int lastElementTake = dp[n-1];


        return max(firstElementTake, lastElementTake);
    }
};