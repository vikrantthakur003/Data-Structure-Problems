class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int minIndex = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                minIndex = i;
                break;
            }
        }
        if(minIndex == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=nums.size()-1;i>minIndex;i--){
            if(nums[i] > nums[minIndex]){
                swap(nums[i],nums[minIndex]);
                break;
            }
        }
        reverse(nums.begin()+minIndex+1, nums.end());
    }
};