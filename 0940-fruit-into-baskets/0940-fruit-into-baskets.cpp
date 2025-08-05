class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int s = 0;
        int r = 0;
        
        unordered_map<int, int> mp;
        int maxLength = 0;
        while(r < n){
           mp[fruits[r]]++;

           while(mp.size() > 2){
                mp[fruits[s]]--;
                if(mp[fruits[s]] == 0){
                    mp.erase(fruits[s]);
                }
                s++;
           }

           int len = r - s + 1;
           maxLength = max(maxLength, len);
           r++;
        }
        return maxLength;
    }
};