#include<bits/stdc++.h>
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int totalSqaure = 0;
        dp[0][0] = matrix[0][0];
        totalSqaure += dp[0][0];
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = matrix[i][0];
            totalSqaure += dp[i][0];
        }

        for (int i = 1; i < m; i++) {
            dp[0][i] = matrix[0][i];
            totalSqaure += dp[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    int left = 0;
                    int top = 0;
                    int topDiagonal = 0;

                    if (j > 0) {
                        left = dp[i][j - 1];
                    }
                    if (i > 0) {
                        top = dp[i - 1][j];
                    }
                    if (i > 0 && j > 0) {
                        topDiagonal = dp[i - 1][j - 1];
                    }

                    dp[i][j] = 1 + min(left, min(top, topDiagonal));
                    totalSqaure += dp[i][j];
                }
            }
        }

        return totalSqaure;
    }
};