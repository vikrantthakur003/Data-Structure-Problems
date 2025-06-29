class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> & dp){
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int rightSide = solve(i, j + 1, m, n, dp);
        int downSide = solve(i + 1, j, m, n, dp);

        return dp[i][j] = rightSide + downSide;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // return solve(0, 0, m, n, dp);

        // m = 5, n = 1
        // first col should be 1
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }

        // m = 1, n = 5
        // first row should be 1
        for(int i=0;i<n;i++){
            dp[0][i] = 1;
        }

        for(int i = 1;i<m; i++){
            for(int j=1;j<n;j++){
                    int rightSide = dp[i][j - 1];
                    int downSide = dp[i-1][j];
                    dp[i][j] = rightSide + downSide;
                }
        }
        return dp[m-1][n-1];
    }
};