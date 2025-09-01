class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> maxheap; // freq, element
        for (auto itr : mp) {
            maxheap.push({itr.second, itr.first});
        }

        string ans = "";
        while (maxheap.size() > 1) {
            pair<int, char> first = maxheap.top();
            maxheap.pop();

            if(maxheap.empty()){
                ans += first.second;
                return ans;
            }

            pair<int, char> second = maxheap.top();
            maxheap.pop();

            ans += first.second;
            ans += second.second;

            pair<int, char> newFirst = { first.first - 1, first.second };
            if (newFirst.first > 0) {
                maxheap.push(newFirst);
            }

            pair<int, char> newSecond = { second.first - 1, second.second };
            if (newSecond.first > 0) {
                maxheap.push(newSecond);
            }
        }

        if (maxheap.empty()) {
            return ans;
        }

        pair<int, char> topElement = maxheap.top();
        if (topElement.first == 1) {
            ans += topElement.second;
            return ans;
        }

        return "";
    }
};