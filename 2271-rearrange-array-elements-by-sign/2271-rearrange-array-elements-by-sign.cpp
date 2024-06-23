class Solution {
public:
    vector<int> findNegativeNumber(vector<int>&arr,int n){
        vector<int>negativeArray;
        for(int i=0;i<n;i++){
            if(arr[i] < 0){
                negativeArray.push_back(arr[i]);
            }
        }
        return negativeArray;
    }
    vector<int> findPositiveNumber(vector<int>&arr,int n){
        vector<int>positiveArray;
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                positiveArray.push_back(arr[i]);
            }
        }
        return positiveArray;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>negativeArray = findNegativeNumber(nums,nums.size());
        vector<int>positiveArray = findPositiveNumber(nums,nums.size());
        int k = 0;
        int i=0;
        int j=0;
        while(i< negativeArray.size() || j<positiveArray.size()){
            if(k%2 != 0){
                nums[k] = negativeArray[i];
                i++;
            }else{
                nums[k] = positiveArray[j];
                j++;
            }
            k++;
        }
        return nums;
    }
};