class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> st;
    void solve(int ind, vector<int>& arr, int target, vector<int>& temp) {
        if (target == 0) {
            if (st.find(temp) == st.end()) {
                result.push_back(temp);
                st.insert(temp);
            }
            
            return;
        }

        if (ind >= arr.size()) {
            return;
        }

        if (arr[ind] <= target) {
            temp.push_back(arr[ind]);
            solve(ind + 1, arr, target - arr[ind], temp);

            temp.pop_back();
        }

        solve(ind + 1, arr, target, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, temp);

        return result;
    }
};