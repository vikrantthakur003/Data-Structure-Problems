class Solution {
public:
    vector<vector<int>> result;
    void findCombination(int ind, vector<int> &arr, int target, vector<int> temp){

        if(target == 0){
            result.push_back(temp);
            return;
        }

        if(ind >= arr.size()){
            return;
        }
        
        if(arr[ind] <= target){
            temp.push_back(arr[ind]);
            findCombination(ind, arr, target - arr[ind], temp);

            temp.pop_back();
        }

        findCombination(ind + 1, arr, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        findCombination(0, candidates, target, temp);

        return result;
    }
};