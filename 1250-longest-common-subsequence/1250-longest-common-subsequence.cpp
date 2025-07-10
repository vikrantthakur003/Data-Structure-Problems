class Solution {
public:
    int solve(int ind1, int ind2, string str1, string str2, vector<vector<int>> &dp){
        if(ind1 >= str1.length() || ind2 >= str2.length()){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        int takeBothString = INT_MIN;
        if(str1[ind1] == str2[ind2]){
            return dp[ind1][ind2] = 1 + solve(ind1 + 1, ind2 + 1, str1, str2, dp);
        } else {
            return dp[ind1][ind2] = max(solve(ind1 + 1, ind2, str1, str2, dp), solve(ind1, ind2 + 1, str1, str2, dp));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // return solve(0, 0, text1, text2, dp);

        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int i=0;i<=m;i++){
            dp[0][i] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};