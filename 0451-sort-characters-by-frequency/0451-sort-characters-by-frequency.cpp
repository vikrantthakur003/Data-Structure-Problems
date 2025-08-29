class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> maxheap;

        for (auto itr : mp) {
            maxheap.push({itr.second, itr.first});
        }

        string result = "";
        while (!maxheap.empty()) {
            result += string(maxheap.top().first, maxheap.top().second);
            maxheap.pop();
        }

        return result;
    }
};