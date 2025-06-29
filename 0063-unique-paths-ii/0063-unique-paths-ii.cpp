class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i >= m || j>=n){
            return 0;
        }

        if(i == m-1 && j == n-1){
            if(obstacleGrid[i][j] == 0){
                return 1;
            } else {
                return 0;
            }
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int rightSide = 0;
        int downSide = 0;
        if( j + 1 < n && obstacleGrid[i][j+1] == 0){
            rightSide = solve(i, j + 1, m, n, obstacleGrid, dp);
        }

        if(i + 1 < m && obstacleGrid[i + 1][j] == 0){
            downSide = solve(i + 1, j, m, n, obstacleGrid, dp);
        }

        return dp[i][j] = rightSide + downSide;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        if(obstacleGrid[0][0] == 1){
            return 0;
        }

        return solve(0, 0, m, n, obstacleGrid, dp);
    }
};