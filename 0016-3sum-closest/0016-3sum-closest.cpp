class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 1 << 30;

        for(int i = 0; i<n; i++){
            int s = i + 1;
            int e = n - 1;

            while(s < e){

                int sum = nums[i] + nums[s] + nums[e];
                if(sum == target){
                    return sum;
                } 
                if(abs(ans - target) > abs(sum - target)){
                    ans = sum;
                } else if( sum > target){
                    e--;
                } else if(sum < target){
                    s++;
                } else {
                    return target;
                }
            }
        }

        return ans;
    }
};