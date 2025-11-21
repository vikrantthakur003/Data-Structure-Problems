class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int> result;
        int m = mat.size();
        int n = mat[0].size();

        for(int d = 0; d<=(m+n-2); d++){ // m + n - 2 === number of diagonals
            if(d % 2 == 0){
                int i = min(d, m - 1);
                int j = d - i;

                while(i >= 0 && j < n){
                    result.push_back(mat[i][j]);
                    i -= 1;
                    j += 1;
                }
            } else {
                int j = min(d, n - 1);
                int i = d - j;

                while(i < m && j >= 0){
                    result.push_back(mat[i][j]);
                    i += 1;
                    j -= 1;
                }
            }
        }

        return result;
    }
};