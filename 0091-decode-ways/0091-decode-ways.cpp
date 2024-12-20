class Solution {
public:
    int helperRecursion(string &str, int index, vector<int>&dp){
        if(index == str.size()){
            return 1;
        }
        if(str[index] == '0'){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int oneDigitDecoded = helperRecursion(str, index+1, dp);
        int twoDigitDecoded = 0;
        if(index + 1 < str.size()){
            int num = stoi(str.substr(index, 2));
            if(num >= 10 && num <=26){
                twoDigitDecoded = helperRecursion(str, index+2, dp);
            }
        }
        return dp[index] = oneDigitDecoded + twoDigitDecoded;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, -1);
        return helperRecursion(s, 0, dp);
    }
};