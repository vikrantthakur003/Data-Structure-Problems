class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int left = 0;
        int right = 0;

        int maxlength = 0;

        while(right < n){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }

            int len = right - left + 1;
            maxlength = max(maxlength, len);
            right++;
        }

        return maxlength;
    }
};