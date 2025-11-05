class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int element = 0;
        for(int i = 0; i<nums.size(); i++){
            element = element ^ nums[i];
        }

        return element;
    }
};