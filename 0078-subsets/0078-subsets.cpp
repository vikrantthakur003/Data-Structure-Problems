class Solution {
public:
    vector<vector<int>> result;
    void findSubsets(vector<int>& nums, int index, vector<int> temp){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        findSubsets(nums, index + 1, temp);

        temp.pop_back();

        findSubsets(nums, index + 1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        findSubsets(nums, 0, temp);

        return result;
    }
};