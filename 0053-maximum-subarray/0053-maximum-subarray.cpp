class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currentSum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i<nums.size(); i++){
            if(currentSum < 0){
                currentSum = nums[i];
            } else {
                currentSum += nums[i];
            }

            if(maxSum < currentSum ){
                maxSum = currentSum;
            }
        }

        return maxSum;
    }
};