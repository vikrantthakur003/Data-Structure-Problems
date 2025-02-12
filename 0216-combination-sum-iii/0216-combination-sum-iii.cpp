class Solution {
public:
    vector<vector<int>> result;
    void findPerfectCombination3(int k, int target, vector<int> temp, vector<int> &arr, int index){
        if(temp.size() == k && target == 0){
             result.push_back(temp);
            return;
        }

        if(index >= arr.size()){
            return;
        }
        
        temp.push_back(arr[index]);
        findPerfectCombination3(k, target - arr[index], temp, arr, index + 1);

        temp.pop_back();

        findPerfectCombination3(k , target, temp, arr, index + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<int> arr;
        for(int i=1;i<=9;i++){
            arr.push_back(i);
        }

     findPerfectCombination3(k, n, temp, arr, 0);

        return result;
    }
};