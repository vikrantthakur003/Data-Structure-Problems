class Solution {
public:
    vector<vector<int>> result;
    void findSubsets(vector<int>&nums, vector<int>&temp, int index){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        findSubsets(nums, temp, index + 1);

        temp.pop_back();
        while(index + 1  <  nums.size() && nums[index] == nums[index+1]){
            index += 1;
        }

        findSubsets(nums, temp, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;

        findSubsets(nums, temp ,0);
        return result;
    }
};