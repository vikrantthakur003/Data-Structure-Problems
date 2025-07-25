class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);
        vector<int> child(n);

        for (int i = 0; i < n; i++) {
            child[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int last = 0; last < i; last++) {

                if ((nums[i] % nums[last] == 0) ||
                    (nums[last] % nums[i] == 0)) {
                        // cout<< nums[i]<<" "<< nums[last]<<endl;
                    int takeValue = 1 + dp[last];
                    if (takeValue > dp[i]) {
                        dp[i] = takeValue;
                        child[i] = last;
                    }
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<< " ";
        // }

        int maxValue = INT_MIN;
        int maxIndex;
        for (int i = 0; i < n; i++) {
            if (maxValue < dp[i]) {
                maxValue = dp[i];
                maxIndex = i;
            }
        }

        vector<int> ans;
        while (child[maxIndex] != maxIndex) {
            ans.push_back(nums[maxIndex]);
            maxIndex = child[maxIndex];
        }

        ans.push_back(nums[maxIndex]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};