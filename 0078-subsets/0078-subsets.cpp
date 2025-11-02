class Solution {
public:
    vector<vector<int>> result;
    void solve(int ind, vector<int> &arr, vector<int> temp){
        if(ind >= arr.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(arr[ind]);
        solve(ind + 1, arr, temp);

        temp.pop_back();
        solve(ind + 1, arr, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        solve(0, nums, tmp);

        return result;
    }
};