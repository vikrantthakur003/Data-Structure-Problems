class Solution {
public:
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i >= text1.size() || j>=text2.size()){
            return 0;
        }
        if(dp[i][j] != -1 ){
            return dp[i][j];
        }

        int takeValue = 0;
        int notTakeValue = 0;
        if(text1[i] == text2[j]){
            takeValue = 1 + solve(i + 1, j + 1, text1, text2, dp);
        } else {
            int skipFromFirstStr = solve(i + 1, j, text1, text2, dp);
            int skipFromSecondStr = solve(i, j + 1, text1, text2, dp);

            notTakeValue = max(skipFromFirstStr, skipFromSecondStr);
        }

        return dp[i][j] = max(takeValue, notTakeValue);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // return solve(0, 0, text1, text2, dp);

        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

        for(int i = n - 1; i>= 0; i--){
            for(int j = m - 1; j>=0; j--){
                int takeValue =0;
                int notTakeValue = 0;

                if(text1[i] == text2[j]){
                    takeValue = 1 + dp[i + 1][j + 1];
                } else {
                    int skipFromFirstStr = dp[i + 1][j];
                    int skipFromSecondStr = dp[i][j + 1];

                    notTakeValue = max(skipFromFirstStr, skipFromSecondStr);
                }

                dp[i][j] = max(takeValue, notTakeValue);
            }
        }

        return dp[0][0];
    }
};