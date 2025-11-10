class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int result = 0;
        int diff = INT_MAX;

        for(int i = 0; i<n; i++){
            int s = i + 1;
            int e = n - 1;

            while(s < e){

                int sum = nums[i] + nums[s] + nums[e];
                if(diff > abs(sum - target)){
                    result = sum;
                    diff = abs(sum - target);
                } else if( sum > target){
                    e--;
                } else if(sum < target){
                    s++;
                } else {
                    return target;
                }
            }
        }

        return result;
    }
};