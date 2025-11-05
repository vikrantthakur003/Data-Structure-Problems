class Solution {
public:
    vector<vector<int>> result;
    bool isElementExists(vector<int> &arr, int element){

        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == element){
                return true;
            }
        }

        return false;
    }
    void solve(int ind, vector<int> &nums, vector<int> temp){
        if(ind >= nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(!isElementExists(temp, nums[i])){
                temp.push_back(nums[i]);

                solve(ind + 1, nums, temp);

                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> temp;
        solve(0, nums, temp);

        return result;
    }
};