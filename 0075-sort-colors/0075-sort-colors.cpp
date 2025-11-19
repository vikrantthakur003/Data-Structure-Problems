class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() - 1;
        int k = 0;

        while(k <= end){
            if(nums[k] == 0){
                swap(nums[start], nums[k]);
                start++;
                k++;
            } else if(nums[k] == 1){
                k++;
            } else {
                swap(nums[k], nums[end]);
                end--;
            }
        }
    }
};