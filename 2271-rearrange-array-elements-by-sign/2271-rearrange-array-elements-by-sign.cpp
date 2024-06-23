class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int oddIndex = 1;
        int evenIndex = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){
                ans[evenIndex] = nums[i];
                evenIndex += 2;
            }else{
                ans[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }
        return ans;
    }
};