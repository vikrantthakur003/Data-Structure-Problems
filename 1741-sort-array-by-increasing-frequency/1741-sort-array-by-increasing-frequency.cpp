struct comp{
    bool operator()(pair<int, int> &a,pair<int, int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> minheap; // freq, element
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto itr : mp){
            minheap.push({itr.second, itr.first});
        }

        vector<int> ans;
        while(!minheap.empty()){
            for(int i = 1; i<=minheap.top().first; i++){
                ans.push_back(minheap.top().second);
            }
            minheap.pop();
        }

        return ans;
    }
};