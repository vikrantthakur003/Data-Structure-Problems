class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int evenIndex = 0;
        int oddIndex = 1;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                result[evenIndex] = nums[i];
                evenIndex += 2;
            } else {
                result[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }
        return result;
    }
};