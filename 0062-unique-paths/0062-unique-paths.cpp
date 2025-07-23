class Solution {
public:
    int solve(int ind1, int ind2, int m, int n, vector<vector<int>> &dp){
        if(ind1 >= m || ind2 >= n){
            return 0;
        }
        if(ind1 == m-1 && ind2 == n-1){
            return 1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        int rightSide = solve(ind1 + 1, ind2, m, n, dp);
        int downSide = solve(ind1, ind2 + 1, m, n, dp);

        return dp[ind1][ind2] = rightSide + downSide;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};