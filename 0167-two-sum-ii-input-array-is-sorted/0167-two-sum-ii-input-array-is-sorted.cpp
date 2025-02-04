class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int startIndex = 0;
        int endIndex = numbers.size()-1;

        while(startIndex <= endIndex){
            if(numbers[startIndex] + numbers[endIndex] == target){
                return {startIndex + 1, endIndex+1};
            } else if(numbers[startIndex] + numbers[endIndex] < target){
                startIndex++;
            } else{
                endIndex--;
            }
        }

        return {-1, -1};
    }
};