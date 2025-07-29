class Solution {
public:
    int solve(int ind1, int ind2, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if(ind1 >= arr.size() || ind2 >= arr.size()){
            return INT_MAX;
        }

        if(ind1 == arr.size() - 1){
            return arr[ind1][ind2];
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        int sameIndex = solve(ind1 + 1, ind2, arr, dp);
        int leftIndex = solve(ind1 + 1, ind2 - 1, arr, dp);
        int rightIndex = solve(ind1 + 1, ind2 + 1, arr, dp);

        return dp[ind1][ind2] = arr[ind1][ind2] + min(sameIndex, min(leftIndex, rightIndex));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minValue = INT_MAX;
        int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int i = 0; i<matrix.size(); i++){
        //     minValue = min(minValue, solve(0, i, matrix, dp));
        // }

        // return minValue;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int ind =  n - 1; ind >= 0; ind--){
            for(int i = n - 1;i >= 0; i--){
                for(int j = ind; j >= 0; j--){
                    int sameIndex = INT_MAX;
                    int nextIndex = INT_MAX;
                    int previousIndex = INT_MAX;
                    if (i < n - 1){
                        sameIndex = dp[i + 1][j];
                    }
                    if(i < n - 1 && j < n - 1){
                        nextIndex = dp[i + 1][j + 1];  
                    }
                    if (i < n - 1 && j > 0 ){
                        previousIndex  = dp[i + 1][j - 1];
                    }

                    int minValue = min(sameIndex, min(nextIndex, previousIndex));
                    if(minValue == INT_MAX){
                         dp[i][j] = matrix[i][j];
                    } else {
                         dp[i][j] = matrix[i][j] + minValue;
                    }
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<dp[i][j]<< " ";
            }
            cout<<endl;
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};