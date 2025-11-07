class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> result(nums.size(), 0);
        int positiveIndex = 0;
        int negativeIndex = 1;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] >= 0){
                result[positiveIndex] = nums[i];
                positiveIndex += 2;
            } else {
                result[negativeIndex] = nums[i];
                negativeIndex += 2;
            }
        }

        return result;
    }
};