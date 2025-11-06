class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp; // element, frequency

        int n = nums.size();
        pair<int, int> result = {-1, -1}; // element frequency

        for(int i = 0; i<n; i++){
            cout<<mp[nums[i]]<<endl;
            if(mp.find(nums[i]) != mp.end() && mp[nums[i]] >= n/2){
                cout<<(mp[nums[i]] > n/2)<<endl;
               int freq = mp[nums[i]] > n/2;
               if(result.second < freq){
                    result.first = nums[i];
                    result.second = freq;
               }
            }

            mp[nums[i]]++;
        }

        return result.first;
    }
};