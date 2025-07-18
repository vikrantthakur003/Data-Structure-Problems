class Solution {
public:
    int solve(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        if(i >= s.length() && j >= p.length()){
            return true;
        }

        if(i < s.length() && j >= p.length()){
            return false;
        }

        if(i >= s.length() && j < p.length()){
            for(int ch = j; ch < p.length(); ch++){
                if(p[ch] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
        } 

        if(p[j] == '*'){
            bool notTakeStar = solve(i, j + 1, s, p, dp);
            bool takeStar = solve(i + 1, j, s, p, dp);

            return dp[i][j] = notTakeStar || takeStar;
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, p, dp);
    }
};