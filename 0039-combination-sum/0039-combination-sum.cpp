class Solution {
public:
    vector<vector<int>> result;
    void findCombination(vector<int> &arr, vector<int> &temp, int index, int target){
        if(index >= arr.size()){
            if(target == 0){
                result.push_back(temp);
            }
            return;
        }

        if(arr[index] <= target){
            temp.push_back(arr[index]);
            findCombination(arr, temp, index, target - arr[index]);
            temp.pop_back();
        }

        findCombination(arr, temp, index + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        findCombination(candidates, temp, 0, target);

        return result;
    }
};