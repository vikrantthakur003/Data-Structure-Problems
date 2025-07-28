class Solution {
public:
    int solve(int ind1, int ind2, vector<vector<int>> & arr, vector<vector<int>> &dp){
        if(ind1 == arr.size() - 1){
            return arr[ind1][ind2];
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        int sameIndex = solve(ind1 + 1, ind2, arr, dp);
        int nextIndex = solve(ind1 + 1, ind2 + 1, arr, dp);

        return dp[ind1][ind2] =  arr[ind1][ind2] + min(sameIndex, nextIndex);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(0, 0, triangle, dp);

        vector<vector<int>> dp(n, vector<int>(m, 0));

        dp[0][0] = triangle[0][0];

        for(int i = 1; i<n; i++){
            for(int j = 0; j<triangle[i].size(); j++){
                int sameIndex = INT_MAX;
                int nextIndex = INT_MAX;

                if(j < triangle[i - 1].size()){
                   sameIndex = dp[i - 1][j]; 
                }
                if(j > 0 ){
                    nextIndex = dp[i - 1][j - 1];
                }
                
                dp[i][j] = triangle[i][j] + min(sameIndex, nextIndex);
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};