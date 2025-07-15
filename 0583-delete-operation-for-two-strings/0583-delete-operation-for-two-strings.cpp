class Solution {
public:
 int longestPalindromicSubsequence(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        if(ind1 >= s1.size() || ind2 >= s2.size()){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = 1 + longestPalindromicSubsequence(ind1 + 1, ind2 + 1, s1, s2, dp);
        } else {
            return dp[ind1][ind2] = max(longestPalindromicSubsequence(ind1 + 1, ind2, s1, s2, dp), longestPalindromicSubsequence(ind1, ind2 + 1, s1, s2, dp));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int lcsLength = longestPalindromicSubsequence(0, 0, word1, word2, dp);

        return (word1.length() + word2.length()) - (2 * (lcsLength));
    }
};