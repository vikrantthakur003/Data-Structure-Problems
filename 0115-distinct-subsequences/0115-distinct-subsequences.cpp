class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j >= s2.size()){
            return 1;
        }

        if(i >= s1.size()){
            if(j >= s2.size()){
                return 1;
            } 
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int matched = 0;
        int notMatched = 0;
        if(s1[i] == s2[j]){
            int takeValue = solve(i + 1, j + 1, s1, s2, dp);
            int notTakeValue = solve(i + 1, j, s1, s2, dp);

            return dp[i][j] =  takeValue + notTakeValue;
        } 

        return dp[i][j] = solve(i + 1, j, s1, s2, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(0, 0, s, t, dp);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){

                if(s[i - 1] == t[j - 1]){
                    int takeValue = dp[i - 1][j - 1];
                    int notTakeValue = dp[i - 1][j];

                    dp[i][j] = (takeValue + notTakeValue)%MOD;
                } else {
                    dp[i][j] = (dp[i - 1][j])%MOD;
                }
            }
        }

        return dp[n][m];
    }
};