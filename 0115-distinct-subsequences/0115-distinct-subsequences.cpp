class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
        if(ind2 >= t.size()){
            return 1;
        }

        if(ind1 >= s.size()){
            if(ind2 >= t.size()){
                return 1;
            } 
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s[ind1] == t[ind2]){
            int takeBothValue = solve(ind1 + 1, ind2 + 1, s, t, dp);
            int takeOneValue = solve(ind1 + 1, ind2, s, t, dp);

            return dp[ind1][ind2] = takeBothValue + takeOneValue;
        } else {
            return dp[ind1][ind2] = solve(ind1 + 1, ind2, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        // return solve(0, 0, s, t, dp);

        vector<vector<long long>> dp(s.size() + 1, vector<long long>(t.size() + 1, 0));

        // for 0 s
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        // for 0 t
        // for(int i=1; i<=m; i++){
        //     dp[0][i] = 0;
        // }

        // dp[0][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m ;j++){
                if(s[i - 1] == t[j - 1]){
                    int takeBothValue = dp[i - 1][j - 1];
                    int takeOneValue = dp[i - 1][j];

                    dp[i][j] = (takeBothValue + takeOneValue) % MOD;
                } else {
                    dp[i][j] = (dp[i - 1][j])%MOD;
                }
            }
        }

        return dp[n][m];
    }
};