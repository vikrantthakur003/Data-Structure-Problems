class Solution {
public:
    int helperRobber(vector<int>&nums, int n){
        vector<int>dp(n, 0);
        if(n < 2){
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2;i<n;i++){
            int includeElement = dp[i-2] + nums[i];
            int excludeElement = dp[i-1];

            dp[i] = max(includeElement, excludeElement);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return nums[0];

        vector<int>skipFirstElement(n-1);
        vector<int>skipLastElement(n-1);

        for(int i=0;i<n-1;i++){
            skipFirstElement[i] = nums[i+1];
            skipLastElement[i] = nums[i];
        }

        int firstSkippingMaximum = helperRobber(skipFirstElement, skipFirstElement.size());
        int lastSkippingMaximum = helperRobber(skipLastElement, skipLastElement.size());

        return max(firstSkippingMaximum,lastSkippingMaximum);
    }
};