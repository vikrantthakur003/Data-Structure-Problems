class Solution {
public:
    int solve(int index, int size, vector<int>& nums, vector<int> & dp){
        if(index >= size){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }
        int takeHouse = nums[index] + solve(index + 2, size, nums, dp);
        int skipHouse = solve(index + 1, size, nums, dp);

        return dp[index] = max(takeHouse, skipHouse);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }
        vector<int> dp(n, -1);

        int skipFirstHouse = solve(1, n, nums, dp);
        fill(dp.begin(), dp.end(), -1);

        int skipLastHouse = solve(0, n - 1, nums, dp);

        return max(skipFirstHouse, skipLastHouse);
    }
};