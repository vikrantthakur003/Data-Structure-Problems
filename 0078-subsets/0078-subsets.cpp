class Solution {
public:
    void findSubsets(vector<int>&nums, vector<vector<int>> &result, vector<int> &temp, int index){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        findSubsets(nums, result,temp, index + 1);

        temp.pop_back();
        findSubsets(nums, result, temp, index + 1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        findSubsets(nums, result,temp, 0);

        return result;
    }
};