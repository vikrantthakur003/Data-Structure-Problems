class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    bool isEqual(string &target, string &original){
        if(target.length() != original.length() + 1){
            return false;
        }

        int i = 0; 
        int j = 0;
        bool isAdded = false;

        while(i < target.length() && j < original.length()){
            if(target[i] == original[j]){
                i++;
                j++;
            } else if(!isAdded){
                i++;
                isAdded = true;
            } else {
                return false;
            }
        }

        return true;
    }
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);

        for(int i = 0; i<n; i++){
            for(int lastIndex = 0; lastIndex < i; lastIndex++){
                if(isEqual(words[i], words[lastIndex]) && 1 + dp[lastIndex] > dp[i]){
                    dp[i] = 1 + dp[lastIndex];
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};