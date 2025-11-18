class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int s1 = 0;
        int s2 = 0;
        int count = 0;

        while(s1 < s.length() && s2<t.length()){
            if(s[s1] == t[s2]){
                s1++;
                s2++;
                count++;
            } else {
                s2++;
            }
        }

        return count == s.size() ? true : false;
    }
};