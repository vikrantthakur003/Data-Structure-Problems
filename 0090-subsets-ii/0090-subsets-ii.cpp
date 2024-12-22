class Solution {
public:
    vector<vector<int>> result;
    void getSubsets(vector<int>&nums, int index, vector<int>&temp){
        // Base Condition
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }
        // Include Element 
        temp.push_back(nums[index]); // Induction
        getSubsets(nums, index+1, temp); // Hypothesis


        //Exclude Element
        temp.pop_back(); // Induction
        while(index + 1 < nums.size() && nums[index] == nums[index+1]){
            index += 1;
        }
        getSubsets(nums, index+1, temp); // Hypothesis
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        getSubsets(nums, 0, temp);

        return result;
    }
};