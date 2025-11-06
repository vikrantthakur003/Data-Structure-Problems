class Solution {
public:
    void sortColors(vector<int>& nums) {
        int oneCount = 0;
        int zeroCount = 0;
        int twoCount = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroCount++;
            } else if(nums[i] == 1){
                oneCount++;
            } else {
                twoCount++;
            }
        }

        int k = 0;
        while(zeroCount != 0){
            nums[k++] = 0;
            zeroCount--;
        }

        while(oneCount != 0){
            nums[k++] = 1;
            oneCount--;
        }

        while(twoCount != 0){
            nums[k++] = 2;
            twoCount--;
        }
    }
};