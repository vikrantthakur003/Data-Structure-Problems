class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);

        for(auto num : nums){
           rightSum -= num;

            ans.push_back(abs(leftSum - rightSum));   
            leftSum += num;    
        }

        return ans;
    }
};