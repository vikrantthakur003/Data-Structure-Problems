class Solution {
public:
    int solve(int i, bool canIbuy, int transactions, vector<int>&arr, vector<vector<vector<int>>>&dp){
        if(i >= arr.size()){
            return 0;
        }

        if(transactions >= 2){
            return 0;
        }

        if(dp[i][canIbuy][transactions] != -1){
            return dp[i][canIbuy][transactions];
        }

        int profit = 0;
        if(transactions <= 2 && canIbuy){
            int buyValue = -arr[i] + solve(i + 1, false, transactions, arr, dp);
            int notBuyValue = solve(i + 1, true, transactions, arr, dp);

            profit = max(buyValue, notBuyValue);
        } else if(transactions <= 2){
            int sellValue = arr[i] + solve(i + 1, true, transactions + 1, arr, dp);
            int notSellValue = solve(i + 1, false, transactions, arr, dp);

            profit = max(sellValue, notSellValue);
        }
        return dp[i][canIbuy][transactions] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        // return solve(0, true, 0, prices, dp);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = n - 1; i>=0; i--){
            for(int canIbuy = 1; canIbuy >=0; canIbuy--){
                for(int transaction = 0; transaction <= 2; transaction++){

                    if(canIbuy){
                        int buyValue = -prices[i] + dp[i + 1][0][transaction];
                        int skipBuy = dp[i + 1][1][transaction];

                        dp[i][canIbuy][transaction] = max(buyValue, skipBuy);
                    } else {
                         if (transaction < 2) {
                            int sellValue = prices[i] + dp[i + 1][1][transaction + 1];
                            int notSellValue = dp[i + 1][0][transaction];

                            dp[i][canIbuy][transaction] = max(notSellValue, sellValue);
                         } else {
                            dp[i][canIbuy][transaction] = dp[i + 1][0][transaction];
                         }
                    }
                }
            }
        }

        return dp[0][1][0];
    }
};