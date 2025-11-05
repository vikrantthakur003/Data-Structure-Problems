class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size(); 
        int sumOfArray = 0;
        int sumShouldBe = n;
        
        for(int i = 0; i<n; i++){
            sumOfArray += nums[i];
            sumShouldBe += i;
        }

        return sumShouldBe - sumOfArray;
    }
};