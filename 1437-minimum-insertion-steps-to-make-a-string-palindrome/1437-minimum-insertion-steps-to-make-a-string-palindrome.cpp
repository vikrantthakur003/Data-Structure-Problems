class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i >= s1.size() ||  j >= s2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int takeValue = 0;
        int notTakeValue = 0;
        if(s1[i] == s2[j]){
            takeValue  = 1 + solve(i + 1, j + 1, s1, s2, dp);
        } else {
            int skipFromFirst = solve(i + 1, j, s1, s2, dp);
            int skipFromSecond = solve(i, j + 1, s1, s2, dp);

            notTakeValue = max(skipFromFirst, skipFromSecond);
        }

        return dp[i][j] = max(takeValue, notTakeValue);
    }
    int minInsertions(string s) {
        int n = s.size();
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int lps = solve(0, 0, s, revStr, dp);

        return n - lps;
    }
};