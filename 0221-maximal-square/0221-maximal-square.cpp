class Solution {
public:
    int solve(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>&dp) {
        if (i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(i, j + 1, matrix, dp);
        int down = solve(i + 1, j, matrix, dp);
        int diagonal = solve(i + 1, j + 1, matrix, dp);

        if (matrix[i][j] == '1') {
           return dp[i][j] = 1 + min({right, down, diagonal});
        }
        return dp[i][j] = 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>>dp(n, vector<int>(m, -1));

        int maxSide = 0;
        // for(int i =0; i<n; i++){
        //     for(int j =0; j<m; j++){
        //         int value = solve(i, j, matrix, dp);
        //         maxSide = max(maxSide, value);
        //     }
        // }

        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i = 0; i<m; i++){
            if(matrix[0][i] == '1'){
                dp[0][i] = 1;

                maxSide = max(maxSide, dp[0][i]);
            }
        }

         for(int i = 0; i<n; i++){
            if(matrix[i][0] == '1'){
                dp[i][0] = 1;

                maxSide = max(maxSide, dp[i][0]);
            }
        }

        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][j] == '1'){
                    int right = dp[i][j - 1];
                    int down = dp[i - 1][j];
                    int diagonal = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({right, down, diagonal});
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide;
    }
};