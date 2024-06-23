class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mpp;

        for(int i=0;i<nums.size();i++){
            int remainingSum = target - nums[i];
            if(mpp.count(remainingSum)){
                return {mpp[remainingSum], i};
            }

            mpp[nums[i]] = i;
        }
        return {};
    }
};