class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i >= n || j >= m){
            return INT_MAX;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        int rightSide = solve(i, j + 1, n, m, grid, dp);
        int bottomSide = solve(i + 1, j, n, m, grid, dp);

        return dp[i][j] =  grid[i][j] + min(rightSide, bottomSide);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // return solve(0, 0, n, m, grid, dp);

        // n = 0 m = 5;
        // for first row
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        // n = 5 m = 0
        // for first col
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n-1][m-1];

    }
};