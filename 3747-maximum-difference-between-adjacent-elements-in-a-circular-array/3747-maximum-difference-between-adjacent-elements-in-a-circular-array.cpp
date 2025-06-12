class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;
        
        for(int i=0;i<nums.size() - 1;i++){
            int diff = abs(nums[i] - nums[i+1]);
            if(diff > maxDiff){
                maxDiff = diff;
            }
        }

        int lastElementDiff = abs(nums[0] - nums[nums.size()-1]);
        if(lastElementDiff > maxDiff){
            maxDiff = lastElementDiff;
        }

        return maxDiff;
    }
};