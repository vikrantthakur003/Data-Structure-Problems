class Solution {
public:
    string lcs(string &s1, string &s2){
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        for(int i=0;i<=s1.size(); i++){
            dp[i][0] = 0;
        }

        for(int i=0;i<=s2.size(); i++){
            dp[0][i] = 0;
        }

        for(int i=1;i<=s1.size(); i++){
            for(int j=1;j<=s2.size(); j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = s1.size();
        int j = s2.size();

        string lcsString = "";
        while(i > 0 && j > 0){
            if(s1[i - 1] == s2[j - 1]){
                lcsString += s1[i - 1];
                i--;
                j--;
            } else {
                if(dp[i][j - 1] > dp[i - 1][j]){
                    j--;
                } else {
                    i--;
                }
            }
        }

        reverse(lcsString.begin(), lcsString.end());
        return lcsString;
    }
    string shortestCommonSupersequence(string str1, string str2) {
       string lcsStr = lcs(str1, str2);
        int i = 0;
        int j = 0;

        string res = "";
        for(auto ch : lcsStr){
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