class Solution {
public:
    vector<vector<int>> result;
    void findUniqueSubsets(vector<int> &nums, int index, vector<int> temp){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        findUniqueSubsets(nums, index + 1, temp);
        while(index + 1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        temp.pop_back();
        findUniqueSubsets(nums, index + 1, temp);
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;

        findUniqueSubsets(nums, 0, temp);

        return result;
    }
};