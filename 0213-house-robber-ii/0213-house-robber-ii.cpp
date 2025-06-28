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
        
        int firstElementTake = houseRobber(0, nums, n - 2, dp);
        for(int i=0;i<dp.size();i++){
            dp[i] = -1;
        }
        int lastElementTake = houseRobber(1, nums, n - 1, dp);

        return max(firstElementTake, lastElementTake);
    }
};