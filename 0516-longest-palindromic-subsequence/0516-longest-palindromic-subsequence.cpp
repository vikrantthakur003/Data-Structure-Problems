class Solution {
public:
    int solve(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        if(ind1 >= s1.size() || ind2 >= s2.size()){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(s1[ind1] == s2[ind2]){
            return 1 + solve(ind1 + 1, ind2 + 1, s1, s2, dp);
        }

        return dp[ind1][ind2] = max(solve(ind1 + 1, ind2, s1, s2, dp), solve(ind1, ind2 + 1, s1, s2, dp));
    }
    int longestPalindromeSubseq(string s) {
        string revereString = s;
        
        reverse(revereString.begin(), revereString.end());
        int n = s.size();
        int m = revereString.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, revereString, dp);
    }
};