class Solution {
public:
    int solve(int ind1, int ind2, vector<vector<int>> &grid, int m, int n, vector<vector<int>>& dp){
        if(ind1 >= m || ind2 >= n){
            return 1e9;
        }

        if(ind1 == m-1 && ind2 == n-1){
            return grid[m - 1][n - 1];
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        int rightSide = grid[ind1][ind2] + solve(ind1 + 1, ind2, grid, m, n, dp);
        int downSide = grid[ind1][ind2] + solve(ind1, ind2 + 1, grid, m, n, dp);

        return dp[ind1][ind2] = min(rightSide, downSide);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, grid, m, n, dp);

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0];
        for(int i = 1; i<n; i++){
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }

        for(int i = 1; i<m; i++){
            dp[i][0] += grid[i][0] + dp[i - 1][0];
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                int rightSide = grid[i][j] + dp[i - 1][j];
                int downSide = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(rightSide, downSide);
            }
        }

        return dp[m - 1][n - 1];
        
    }
};