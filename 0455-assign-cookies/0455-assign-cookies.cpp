class Solution {
public:
    int solve(int i, int j, vector<int>&g, vector<int>&s, vector<vector<int>> &dp){
        if(j >= s.size() || i >= g.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int takeValue = INT_MIN;
        if(s[j] >= g[i]){
            takeValue  = 1 + solve(i + 1, j + 1, g, s, dp);
        }
        int notTakeValue = solve(i, j + 1, g, s, dp);

        return dp[i][j] = max(takeValue, notTakeValue);
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //    return solve(0, 0, g, s, dp);

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // for(int i = n - 1; i>= 0; i--){
        //     for(int j = m - 1; j>=0; j--){
        //         int takeValue = INT_MIN;
        //         if(s[j] >= g[i]){
        //             takeValue = dp[i + 1][j + 1] + 1;
        //         }
        //         int notTakeValue = dp[i][j + 1];

        //         dp[i][j] = max(takeValue, notTakeValue);
        //     }
        // }

        // return dp[0][0];

        int i = 0;
        int j = 0;
        int ans = 0;
        while(i <n && j<m){
            if(s[j] >= g[i]){
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};