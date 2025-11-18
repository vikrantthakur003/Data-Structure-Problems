class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size() - 1;

        vector<int> ans;
        while(s <= e){
            int squareA = nums[s] * nums[s];
            int squareB = nums[e] * nums[e];

            if(squareA >= squareB){
                ans.push_back(squareA);
                s++;
            } else if(squareA < squareB) {
                ans.push_back(squareB);
                e--;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};