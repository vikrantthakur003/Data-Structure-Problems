class Solution {
public:
    int solve(int i, int j, vector<int>&g, vector<int>& s, int n, int m){
        if(i >= n){
            return 0;
        }
        if(j >= m){
            return 0;
        }

        int takeValue = 0;
        int notTakeValue = 0;
        if(s[j] >= g[i]){
            takeValue = 1 + solve(i + 1, j + 1, g, s, n, m);
        } else {
            notTakeValue = solve(i, j + 1, g, s, n, m);
        }
    
        return max(takeValue, notTakeValue);
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // return solve(0, 0, g, s, n, m);
        int i = 0;
        int j = 0;

        while(i<n && j<m){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }

        return i;
    }
};