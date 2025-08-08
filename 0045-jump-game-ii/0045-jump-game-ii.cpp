class Solution {
public:
    int solve(int i, vector<int> &arr, vector<int>&dp){
        if(i >= arr.size() - 1){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int minValue = INT_MAX;
        for(int j = 1; j<=arr[i]; j++){
            int jump = solve(i + j, arr, dp);

            if(jump != INT_MAX){
                minValue = min(minValue, jump + 1);
            }
        }

        return dp[i] = minValue;
    }
    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};