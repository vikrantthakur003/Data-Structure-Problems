class Solution {
public:
    int recursionAppraoch(int n, vector<int>&cost, vector<int>&dp){
        if(n == 0){
            return cost[0]; 
        }
        if(n == 1){
            return cost[1];
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = min(recursionAppraoch(n-1,cost,dp), recursionAppraoch(n-2, cost,dp)) + cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        return min(recursionAppraoch(n-1, cost, dp), recursionAppraoch(n-2, cost,dp));
    }
};