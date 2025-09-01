class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
       
       sort(temp.begin(), temp.end());

       unordered_map<int, int> mp; // element, rank

        int rank = 0; 
        
       for (int x : temp) {
            if (mp.find(x) == mp.end()) {
                mp[x] = ++rank;
            }
        }

       for(int i = 0; i<n; i++){
            arr[i] = mp[arr[i]];
       }
        return arr;
    }
};