class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        vector<int> result(n, 0);
        int k = 0;
        int noOfPivot = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] < pivot){
                result[k++] = nums[i];
            } else if(nums[i] == pivot){
                noOfPivot++;
            }
        }

        while(noOfPivot != 0){
            result[k++] = pivot;
            noOfPivot--;
        }

        for(int i = 0; i<n; i++){
            if(nums[i] > pivot){
                result[k++] = nums[i];
            }
        }

        return result;
    }
};