class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int noOfMatrix = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int minValue = dp[i][j];
                for (int k = j; k >= 0 && minValue > 0; k--) {
                    minValue = min(minValue, dp[i][k]);
                    noOfMatrix += minValue;
                }
            }
        }

        return noOfMatrix;
    }
};