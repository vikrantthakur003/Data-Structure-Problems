class Solution {
public:
    int recursionAppraoch(int n, vector<int>&cost, vector<int>&dp){
        if(n == 0) return cost[0]; 
        if(n == 1) return cost[1];

        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = min(recursionAppraoch(n-1,cost,dp), recursionAppraoch(n-2, cost,dp)) + cost[n];
    }

    int tabulationAppraoch(int n, vector<int>&cost){
        vector<int>dp(n+1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[n-1], dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int>dp(n+1, -1);
        // return min(recursionAppraoch(n-1, cost, dp), recursionAppraoch(n-2, cost,dp));

        return tabulationAppraoch(n, cost);
    }
};