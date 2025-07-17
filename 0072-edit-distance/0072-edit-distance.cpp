class Solution {
public:
    int solve(int ind1, int ind2, string &s1, string& s2, vector<vector<int>> &dp) {
        if (ind1 == s1.size()) {
            return s2.size() - ind2;
        }
        if (ind2 == s2.size()) {
            return s1.size() - ind1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if (s1[ind1] == s2[ind2]) {
            return dp[ind1][ind2] = solve(ind1 + 1, ind2 + 1, s1, s2, dp);
        } else {
            // replacemenet
            int replareCharacter = 1 + solve(ind1 + 1, ind2 + 1, s1, s2, dp);

            // removing
            int removeCharacter = 1 + solve(ind1 + 1, ind2, s1, s2, dp);

            // insertion
            int insertCharacter = 1 + solve(ind1, ind2 + 1, s1, s2, dp);

            return dp[ind1][ind2] = min(replareCharacter, min(removeCharacter, insertCharacter));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2, dp);
    }
};