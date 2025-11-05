class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(int ind, string &s, vector<int> &dp){
        if(ind >= s.length()){
            return true;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        bool isExist = false;
        for(int i = ind; i<s.length(); i++){
            string newStr = s.substr(ind, i - ind + 1);

            if(mp.find(newStr) != mp.end()){
                int newIndex = i + 1;

                isExist = solve(newIndex, s, dp);
                if(isExist){
                    return dp[ind] = true;
                }
            }
        }

        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.size(), -1);
        for(int i = 0; i<wordDict.size(); i++){
            mp[wordDict[i]] = true;
        }

        return solve(0, s, dp);
    }
};