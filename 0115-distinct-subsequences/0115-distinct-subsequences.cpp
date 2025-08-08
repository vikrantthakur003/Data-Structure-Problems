class Solution {
public:
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
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, dp);
    }
};