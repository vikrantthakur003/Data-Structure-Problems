class Solution {
public:
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
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(0, 0, s, t, dp);
    }
};