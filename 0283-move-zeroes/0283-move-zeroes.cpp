class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int noOfZeros = 0;
        int k = 0;
 
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                noOfZeros++;
            } else {
                nums[k++] = nums[i];
            }
        }

        while(noOfZeros != 0){
            nums[k++] = 0;
            noOfZeros--;
        }
    }
};