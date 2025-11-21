class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 1);

        int n = nums.size();
        int product = 1;

        for(int i = 0; i<n; i++){
            ans[i] = product;
            product *= nums[i];
        }

        product = 1;
        for(int i = n - 1; i>= 0; i--){
            ans[i] *= product;
            product *= nums[i];
        }

        return ans;
    }
};