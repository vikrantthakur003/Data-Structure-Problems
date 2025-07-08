class Solution {
public:
    int solve(int ind, int currentTarget, vector<int>&arr, int target, int n){
        if(ind >= n){
            return currentTarget == target;
        }

        int takePlusSign = solve(ind + 1, currentTarget + arr[ind], arr, target, n);
        int takeSubstractSign = solve(ind + 1, currentTarget - arr[ind], arr, target, n);

        return takeSubstractSign + takePlusSign;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();

        return solve(0, 0, nums, target, n);
    }
};