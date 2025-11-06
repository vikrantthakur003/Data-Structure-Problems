class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int oddIndex = 1;
        for(int evenIndex = 0; evenIndex < nums.size(); evenIndex += 2){

            if(nums[evenIndex] % 2 == 1){

                while(nums[oddIndex] % 2 == 1){
                    oddIndex += 2;
                }

                swap(nums[evenIndex], nums[oddIndex]);
            }
        }

        return nums;
    }
};