class Solution {
public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i + 1 == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int minValue = INT_MAX;
        for(int k = i + 1; k<j; k++){
            int value = (arr[j] - arr[i]) + solve(i, k, arr, dp) + solve(k, j, arr, dp);

            minValue = min(minValue, value);
        }

        return dp[i][j] = minValue;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int> (size, -1));
        return solve(0, cuts.size() - 1, cuts, dp);
    }
};