class Solution {
public:
    int numberOfSubstrings(string s) {
        int distinctElement = 0;
        vector<int> hash(3, 0);
        int left = 0;
        int right = 0;
        int res = 0;
        int prefix = 0;

        while(right < s.length()){
            if(hash[s[right] - 'a'] == 0){
                distinctElement++;
            }

            hash[s[right] - 'a']++;

            while(left < right && hash[s[left] - 'a'] > 1){
                hash[s[left] - 'a']--;
                left++;
                prefix++;
            }


            if(distinctElement == 3){
                res += prefix + 1;
            }
            right++;
        }

        return res;
    }
};