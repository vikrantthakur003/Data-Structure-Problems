class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFre = 0;
        int left = 0;
        int right = 0;
        int maxLength = 0;
        unordered_map<char, int> count;

        while(right < s.length()){
            count[s[right]]++;

            maxFre = max(maxFre, count[s[right]]);

            while((right - left + 1) - maxFre > k){
                count[s[left]]--;
                left++;
            }

            int len = right - left + 1;
            maxLength = max(maxLength, len);
            right++;
        }

        return maxLength;
    }
};