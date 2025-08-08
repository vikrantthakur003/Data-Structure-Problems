class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int takeValue = 0;
                int notTakeValue = 0;

                if (str1[i] == str2[j]) {
                    takeValue = 1 + dp[i + 1][j + 1];
                } else {
                    int skipFirst = dp[i + 1][j];
                    int skipSecond = dp[i][j + 1];

                    notTakeValue = max(skipFirst, skipSecond);
                }

                dp[i][j] = max(takeValue, notTakeValue);
            }
        }

        int row = 0;
        int col = 0;
        string lcs = "";

        while (row < n && col < m) {
            if (str1[row] == str2[col]) {
                lcs += str1[row];
                row++;
                col++;
            } else {
                if (dp[row + 1][col] >= dp[row][col + 1]) {
                    row++;
                } else {
                    col++;
                }
            }
        }

        string res = "";
        int i = 0;
        int j = 0;

        for(auto ch : lcs){
            while(ch != str1[i]){
                res += str1[i];
                i++;
            }

            while(ch != str2[j]){
                res += str2[j];
                j++;
            }

            res += ch;
            i++;
            j++;
        }

        res += str1.substr(i) + str2.substr(j);

        return res;
    }
};