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

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, grid, m, n, dp);
    }
};