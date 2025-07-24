class Solution {
public:
    int solve(int ind1, int ind2, vector<vector<int>>&arr, vector<vector<int>> &dp){
        if(ind1 >= arr.size() || ind2 >= arr[ind1].size()){
            return 0;
        }

        if(arr[ind1][ind2] == 1){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(ind1 == arr.size() - 1 && ind2 == arr[ind1].size() - 1){
            return 1;
        }
        int rightSide = solve(ind1 + 1, ind2, arr, dp);
        int downSide = solve(ind1, ind2 + 1, arr, dp);

        return dp[ind1][ind2] = rightSide + downSide;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, obstacleGrid, dp);

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0;i<n; i++){
            if(obstacleGrid[0][i] == 1){
                break;
            }
            dp[0][i] = 1;
        }

        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            dp[i][0] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] != 1){
                    int rightSide = dp[i - 1][j];
                    int downSide = dp[i][j - 1];

                    dp[i][j] = rightSide + downSide;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};