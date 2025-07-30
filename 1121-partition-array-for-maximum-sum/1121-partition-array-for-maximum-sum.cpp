class Solution {
public:
    int solve(int i, int k, vector<int>&arr, vector<int>& dp){
        if(i >= arr.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int maxAns = 0;
        int maxValue = 0;
        for(int j = i; j < min(i + k, (int)arr.size()); j++){
            maxValue = max(maxValue, arr[j]);
            int length = j - i + 1;

            int cost = maxValue * length + solve(j + 1, k, arr, dp);

            maxAns = max(maxAns, cost);
        }

        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return solve(0, k, arr, dp);
    }
};