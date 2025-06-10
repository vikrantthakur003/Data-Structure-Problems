class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        int evenMaxiMum = INT_MAX;
        int oddMaxiMum = INT_MIN;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        };

        for(auto it : mp){
            if(it.second % 2 == 0 && it.second > 0){
               evenMaxiMum = min(it.second, evenMaxiMum);
            } 
            if(it.second % 2 != 0) {
                oddMaxiMum = max(it.second, oddMaxiMum);
            }
        }
        return oddMaxiMum - evenMaxiMum;
    }
};