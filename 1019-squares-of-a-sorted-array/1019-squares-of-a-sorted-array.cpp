class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int insertionPos = n - 1;

        vector<int> ans(n, 0);
        while(s <= e){
            int squareA = nums[s] * nums[s];
            int squareB = nums[e] * nums[e];

            if(squareA > squareB){
                ans[insertionPos] = squareA;
                s++;
            } else {
                ans[insertionPos] = squareB;
                e--;
            }
            insertionPos--;
        }

        return ans;
    }
};