class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {
        if (i >= triangle.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int takeSameIndex = solve(i + 1, j, triangle, dp);
        int takeNextIndex = solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(takeSameIndex, takeNextIndex);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(0, 0, triangle, dp);

        vector<vector<int>> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i].resize(triangle[i].size(), 0);
        }

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int takeSameIndex = INT_MAX;
                int takeNextIndex = INT_MAX;

                if (j < triangle[i - 1].size()){
                    takeSameIndex = dp[i - 1][j];
                }
                if (j > 0) {
                    takeNextIndex = dp[i - 1][j - 1];
                }

                dp[i][j] = triangle[i][j] + min(takeSameIndex, takeNextIndex);
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};