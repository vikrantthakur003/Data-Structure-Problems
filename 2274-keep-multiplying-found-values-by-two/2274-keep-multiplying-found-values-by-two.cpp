class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        int n = nums.size();
        unordered_set<int> st;

        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }

        while(true){
            if(st.count(original)){
                original = 2 * original;
            } else {
                return original;
            }
        }

        return original;
    }
};