class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> good(n, 0);
        vector<int> ans(n - k + 1);

        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i - 1] + 1){
                good[i] = 1;
            }
        }

        // first window
        int count = 0;
        for(int i = 1; i<k; i++){
            count += good[i];
        }

        // slide window
        for(int start = 0; start <= (n - k); start++){
            if(count == k - 1){
                ans[start] = nums[start + k - 1]; // get last element because it is sorted and consecutive window
            } else {
                ans[start] = -1;
            }

            if(start + k < n){
                count -= good[start + 1];
                count += good[start + k];
            }
        }

        return ans;
    }
};