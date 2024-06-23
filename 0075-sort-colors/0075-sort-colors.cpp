class Solution {
public:
    void sortColors(vector<int>& nums) {
        long long onesCount = 0;
        long long zeroCount = 0;
        long long twosCount = 0;
        int i=0;
        while(i<nums.size()){
            if(nums[i] == 1){
                onesCount++;
            }else if(nums[i] == 2){
                twosCount++;
            }else{
                zeroCount++;
            }
            i++;
        }
        int k =0;
        while(zeroCount != 0){
            nums[k++] = 0;
            zeroCount--;
        }
        while(onesCount != 0){
            nums[k++] = 1;
            onesCount--;
        }
        while(twosCount != 0){
            nums[k++] = 2;
            twosCount--;
        }
    }
};