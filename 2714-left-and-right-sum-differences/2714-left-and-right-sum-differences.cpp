class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);

        for(int i = 0; i<n; i++){
            int left = leftSum + nums[i];
            int right = rightSum - left;

            ans.push_back(abs(leftSum - right));   
            leftSum += nums[i];         
        }

        return ans;
    }
};