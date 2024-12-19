class Solution {
public:
    int helperRecursion(const string& str, int index){
        if(str[index] == '0'){
            return 0;
        }
        if(index == str.size()){
            return 1;
        }

        int oneDigitDecoded = helperRecursion(str, index+1);
        int twoDigit = 0;
        if(index + 1 < str.size()) {
        int num = stoi(str.substr(index, 2));
            if(num >= 10 && num <= 26 ){
            twoDigit = helperRecursion(str, index+2);
            }
        }
        
        return oneDigitDecoded + twoDigit;
    }

    int helperMemo(string &str, vector<int>&dp, int index){
        if(str[index] == '0') return 0;
        if(index == str.size()) return 1;

        if(dp[index] != -1) return dp[index];

        int oneDigitDecoded = helperMemo(str, dp, index+1);
        int twoDigitDecoded = 0;

        if(index + 1 < str.size()){
            int num = stoi(str.substr(index, 2));
            if(num >=10 && num <=26 ){
                twoDigitDecoded = helperMemo(str, dp, index+2);
            }
        }

        return dp[index] = oneDigitDecoded + twoDigitDecoded;
    }
    int numDecodings(string s) {
        // return helperRecursion(s,0);
        vector<int>dp(s.size() + 1, -1);
        return helperMemo(s,dp, 0);
    }
};