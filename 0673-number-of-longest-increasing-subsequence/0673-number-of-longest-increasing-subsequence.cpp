class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        // count[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int last = i - 1; last >= 0; last--) {
                if (nums[i] > nums[last]) {
                    if (1 + dp[last] > dp[i]) {
                        count[i] = count[last];
                        dp[i] = 1 + dp[last];
                    } else if (1 + dp[last] == dp[i]) {
                        count[i] += count[last];
                    }
                }
            }
        }

        int maxValue = *max_element(dp.begin(), dp.end());
        int result = 0;
        for (int i = 0; i < n; i++) {
           if(dp[i] == maxValue){
                result += count[i];
           }
        }

        return result;
    }
};