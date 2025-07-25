class Solution {
public:
    bool isEqual(string target, string original) {
        if (target.length() != original.length() + 1)
            return false;

        int i = 0, j = 0;
        bool added = false;

        while (i < target.length() && j < original.length()) {
            if (target[i] == original[j]) {
                i++;
                j++;
            } else if (!added) {
                i++;
                added = true;
            } else {
                return false;
            }
        }

        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
        vector<int> dp(n, 1);
        int maxValue = INT_MIN;
        for (int i = 0; i < n; i++) {

            for (int last = 0; last < i; last++) {
                if(isEqual(words[i], words[last]) && dp[last] + 1 > dp[i]){
                    dp[i] = dp[last] + 1;
                }
            }
            maxValue = max(maxValue, dp[i]);
        }

        return maxValue;
    }
};