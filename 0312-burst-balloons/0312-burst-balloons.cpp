class Solution {
public:
    int  solve(int i, int j, vector<int>&nums, vector<vector<int>>& dp){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maxValue = INT_MIN;
        for(int k = i; k <= j; k++){
            int cost = nums[i - 1] * nums[k] * nums[j + 1] + solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp);
            maxValue = max(maxValue, cost); 
        }

        return dp[i][j] = maxValue;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int c = nums.size();

        // vector<vector<int>>dp(n + 2, vector<int>(n + 2, -1));
        // return solve(1, n, nums, dp);

        vector<vector<int>>dp(c, vector<int>(c, 0));

        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                int maxValue = INT_MIN;
                for(int k = i; k <= j; k++){
                    int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    maxValue = max(maxValue, cost);
                }

                dp[i][j] = maxValue;
            }
        }

        for(int i = 0; i< c; i++){
            for(int j = 0; j< c; j++){
                cout<<dp[i][j]<< " ";
            }
            cout<<endl;
        }

        return dp[1][n];
    }
};