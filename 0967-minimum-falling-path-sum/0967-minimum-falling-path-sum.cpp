class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i >=matrix.size()  || j >= matrix.size()){
            return INT_MAX;
        }

        if(i == matrix.size() - 1){
            return matrix[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int takeSameIndex = solve(i+1, j, matrix, dp);
        int takeNextIndex = solve(i+1, j+1, matrix, dp);
        int takePreviousIndex = solve(i+1, j-1, matrix, dp);


        return dp[i][j] = matrix[i][j] + min(takeSameIndex, min(takeNextIndex, takePreviousIndex));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int minValue = INT_MAX;
        int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));

        // for(int i=0;i<matrix.size();i++){
        //     minValue = min(minValue, solve(0, i, matrix, dp));
        // }
        
        // return minValue;


        // Tabulation
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int takeSameIndex = INT_MAX;
                int takePreviousIndex = INT_MAX;
                int takeNextIndex = INT_MAX;
                if(i > 0){
                    takeSameIndex = dp[i - 1][j];
                }
                if(i > 0 && j > 0){
                    takePreviousIndex = dp[i - 1][j - 1];
                }

                if(i > 0 && j < n - 1){
                    takeNextIndex = dp[i - 1][j + 1];
                }

                int minValue = min(takeSameIndex, min(takePreviousIndex, takeNextIndex));

                dp[i][j] = matrix[i][j] + minValue;
            }
        }


        int minValue = INT_MAX;
        for(int i=0;i<n;i++){
            minValue = min(minValue, dp[n-1][i]);
        }

        return minValue;
    }
};