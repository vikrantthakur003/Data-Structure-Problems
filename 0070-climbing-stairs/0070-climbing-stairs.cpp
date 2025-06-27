class Solution {
public:
    int solve(int n, vector<int> &dp){ // tabulation
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    int climbStairs(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> dp(n + 1, -1);
        // solve(n, dp);

        // tabulation
        // dp[0]= 1;
        // dp[1] = 1;

        // for(int i=2;i<=n;i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }

        // optimization
        int prev2 = 1;
        int prev = 1;
        int curr;
        for(int i=2;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
        // return dp[n];
    }
};