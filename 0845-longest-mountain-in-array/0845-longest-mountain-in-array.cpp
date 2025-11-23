class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> up(n, 0);
        vector<int> down(n, 0);

        for(int i = 1; i<n; i++){
            if(arr[i] > arr[i - 1]){
                up[i] = up[i - 1] + 1;
            }
        }

        for(int i = n - 2; i>=0; i--){
            if(arr[i] > arr[i + 1]){
                down[i] = down[i + 1] + 1;
            }
        }

        int ans = 0;

        for(int i = 1; i<n - 1; i++){
            if(down[i] > 0 && up[i] > 0){
                ans = max(ans, (down[i] + up[i] + 1));
            }
        }

        return ans;
    }
};