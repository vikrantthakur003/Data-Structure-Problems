class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.length()) {
            return 0;
        }
        int maxLength = INT_MIN;
        unordered_map<char, int> mp;

        int left = 0;
        int right = 0;
        while (right < s.length()) {
            if (mp.count(s[right]) && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }
            int len = right - left + 1;
            maxLength = max(maxLength, len);
            mp[s[right]] = right;
            right++;
        }

        return maxLength;
    }
};