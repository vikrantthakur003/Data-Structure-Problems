class Solution {
public:
    vector<vector<int>> result;
    void findCombination(vector<int>&arr, int target, vector<int> &temp, int index){
         if(target == 0){
            result.push_back(temp);
            return;
        }  
        if(index >= arr.size()){
           return;
        }
        if(arr[index] <= target){
            temp.push_back(arr[index]);
            findCombination(arr, target - arr[index], temp, index + 1);

            temp.pop_back();
        }

        while(index+1 < arr.size() && arr[index] == arr[index + 1]){
            index++;
        }
        findCombination(arr, target, temp, index + 1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, target, temp, 0);
        return result;
    }
};