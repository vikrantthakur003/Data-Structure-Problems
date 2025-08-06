class Solution {
public:
    int atMost(vector<int>&nums, int k){
        int left = 0;
        int right = 0;
        int res = 0;
        
        while(right < nums.size()){
            if(nums[right] % 2 == 1){
                k--;
            }

            while(k < 0){
               if(nums[left] % 2 == 1){
                    k++;
               }
                left++;
            }

            res += right - left + 1;
            right++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};