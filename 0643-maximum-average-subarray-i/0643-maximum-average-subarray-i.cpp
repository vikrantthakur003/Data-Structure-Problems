class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int windowSum = 0;

        for(int i = 0; i<k; i++){
            windowSum += nums[i];
        }

        int maxxSum = windowSum;

        for(int i = k; i<n; i++){
            windowSum = windowSum - nums[i - k] + nums[i];

            if(windowSum > maxxSum){
                maxxSum = windowSum;
            }
        }

        return static_cast<double> (maxxSum) / k;
    }
};