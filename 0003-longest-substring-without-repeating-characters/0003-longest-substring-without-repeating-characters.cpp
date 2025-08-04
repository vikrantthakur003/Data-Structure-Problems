class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()){
            return 0;
        }
        int maxLength = INT_MIN;
        for(int i = 0; i<s.length(); i++){
             unordered_map<char, int> mp;
            for(int j = i; j<s.length(); j++){
                if(mp[s[j]] == 1){
                    break;
                }
                int len = j - i + 1;
                maxLength = max(maxLength, len);
                mp[s[j]] = 1;
            }
        }
        return maxLength;
    }
};