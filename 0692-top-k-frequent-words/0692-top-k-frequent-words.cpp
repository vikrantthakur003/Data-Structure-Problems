struct Comp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first)
            return a.second < b.second; // Higher lex order comes first
        return a.first > b.first; // Lower frequency comes first
    }
};
class Solution {
public:
    // bool static comp(string &s1, string &s2){
    //     return s1.size() < s2.size();
    // }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int> mp;
        int n = words.size();
        for(int i = 0; i<n; i++){
            mp[words[i]]++;
        }

 priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> minheap;

        for(auto itr : mp){
            minheap.push({itr.second, itr.first});

            if(minheap.size() > k){
                minheap.pop();
            }
        }

        vector<string> ans;
        while(!minheap.empty()){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};