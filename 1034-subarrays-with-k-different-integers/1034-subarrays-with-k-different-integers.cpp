class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_map<int, int> count;
        while(right < nums.size()){

            if(count[nums[right]] == 0){
                k--;
            }
            count[nums[right]]++;

            while(k < 0){
                count[nums[left]]--;

                if(count[nums[left]] == 0){
                    k++;
                }
                left++;
            }

            res += right - left + 1;
            right++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};