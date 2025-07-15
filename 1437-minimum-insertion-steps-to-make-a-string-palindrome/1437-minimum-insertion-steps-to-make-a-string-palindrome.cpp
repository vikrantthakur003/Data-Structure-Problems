class Solution {
public:
    int solve(int start, int end, string s, vector<vector<int>> &dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }
        if(s[start] == s[end]){
            return dp[start][end] = solve(start + 1, end - 1, s, dp);
        } else {
            return dp[start][end] =  1 + min(solve(start + 1, end, s, dp), solve(start, end - 1, s, dp));
        }
    }

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
    int minInsertions(string s) {
        int n = s.size();
        // int start = 0;
        // int end = s.length() - 1;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(start, end, s, dp);
        string reverseStr = s;
        reverse(reverseStr.begin(), reverseStr.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n - longestPalindromicSubsequence(0, 0, s, reverseStr, dp);
    }
};