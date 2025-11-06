class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // sun, frequency
        
        mp[0] = 1;
        int count = 0;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];

            int diff = sum - k;
            if(mp.find(diff) != mp.end()){
                count += mp[diff];
            }

            mp[sum]++;
        }

        return count;
    }
};