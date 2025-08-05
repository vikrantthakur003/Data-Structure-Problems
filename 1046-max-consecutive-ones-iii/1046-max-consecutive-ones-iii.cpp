class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int n = nums.size();

        // for(int i = 0; i<n; i++){
        //      int zeros = 0;
        //     for(int j = i; j<n;j++){
        //         if(nums[j] == 0){
        //             zeros++;
        //         }

        //         if(zeros <= k){
        //             int len = j - i + 1;
        //             maxLength = max(maxLength, len);
        //         } else {
        //             break;
        //         }

        //     }
        // }
        // return maxLength;

        int start = 0;
        int right = 0;
        int zeros = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeros++;

                while(zeros > k){
                    if(nums[start] == 0){
                        zeros--;
                    }
                    start++;
                }
            }

            int len = right - start + 1;
            maxLength = max(maxLength, len);
            right++;
        }

        return maxLength;
    }
};