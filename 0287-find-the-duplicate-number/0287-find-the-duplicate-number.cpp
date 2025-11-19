class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = (left + right)/2;

            int count = 0;
            for(auto ele : nums){
                count += (ele <= mid);
            }

            if(count > mid){
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};