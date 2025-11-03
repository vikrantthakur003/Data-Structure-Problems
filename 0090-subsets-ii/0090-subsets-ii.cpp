class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>>st;
    void getSubsets(int ind, vector<int> &arr, vector<int> temp){
        if(ind >= arr.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(arr[ind]);
        getSubsets(ind + 1, arr, temp);

        while(ind + 1 < arr.size() && arr[ind] == arr[ind + 1]){
            ind++;
        }

        temp.pop_back();
        getSubsets(ind + 1, arr, temp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());

        getSubsets(0, nums, temp);

        return result;
    }
};