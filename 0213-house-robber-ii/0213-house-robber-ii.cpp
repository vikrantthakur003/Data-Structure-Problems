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
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        // vector<int> dp(n, -1);

        // int skipFirstHouse = solve(1, n, nums, dp);
        // fill(dp.begin(), dp.end(), -1);

        // int skipLastHouse = solve(0, n - 1, nums, dp);

        // return max(skipFirstHouse, skipLastHouse);

        vector<int> dp(n, 0);

        // only take first house
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for(int i=2; i<n-1; i++){
            int takeHouse = nums[i] + dp[i - 2];
            int skipHouse = dp[i - 1];

            dp[i] = max(takeHouse, skipHouse);
        }

        int takefirstHouse = dp[n - 2];

        fill(dp.begin(), dp.end(), 0);

        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);

        for(int i=3;i<n;i++){
            int takeHouse = nums[i] + dp[i - 2];
            int skipHouse = dp[i - 1];

            dp[i] = max(takeHouse, skipHouse);
        }

        int takeLastHouse = dp[n - 1];

        return max(takefirstHouse, takeLastHouse);
    }
};