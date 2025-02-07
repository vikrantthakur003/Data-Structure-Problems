class Solution {
public:
    void findSubsets(vector<int>&nums, vector<vector<int>>&result, vector<int>&temp, int index){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        findSubsets(nums, result, temp, index + 1);

        temp.pop_back();
        if(index + 1 <  nums.size() && nums[index] == nums[index+1]){
            index += 1;
        }

        findSubsets(nums, result, temp, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int>temp;

        findSubsets(nums, result, temp ,0);
        return result;
    }
};