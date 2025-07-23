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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, obstacleGrid, dp);
    }
};