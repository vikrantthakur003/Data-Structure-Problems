class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_set<int> st;
        for(int i = 0; i<nums.size(); i++){
            st.insert(nums[i]);
        }

        int ans = 1;
        while(true){
            if(!st.count(ans)){
                return ans;
            }
            ans++;
        }

        return ans;
    }
};