class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> hash, windowHash;

        for (char ch : t) hash[ch]++;

        int required = hash.size();
        int formed = 0;
        int left = 0, right = 0;
        int minLength = INT_MAX, startIndex = -1;

        while (right < s.size()) {
            windowHash[s[right]]++;

            if (hash.count(s[right]) && windowHash[s[right]] == hash[s[right]]) {
                formed++;
            }

            while (formed == required) {
                int len = right - left + 1;
                if (len < minLength) {
                    minLength = len;
                    startIndex = left;
                }

                char removeCh = s[left];
                windowHash[removeCh]--;

                if (hash.count(removeCh) && windowHash[removeCh] < hash[removeCh]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};
