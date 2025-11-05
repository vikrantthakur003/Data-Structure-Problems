class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int noOfZeros = 0;
        vector<int> temp;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                noOfZeros++;
            } else {
                temp.push_back(nums[i]);
            }
        }

        while(noOfZeros != 0){
            temp.push_back(0);
            noOfZeros--;
        }

        nums = temp;
    }
};