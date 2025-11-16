class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> numSet(nums.begin(), nums.end());

       int maxLength = 0;
        unordered_map<int, int> mp; // element, largest Consecutive length
        for(auto currentNum : nums){
            int nextNum = currentNum;


            while(numSet.count(nextNum)){
                numSet.erase(nextNum);
                nextNum++;
            }

            int currentSequenceLength = nextNum - currentNum;
            if(mp.count(nextNum)){
                currentSequenceLength += mp[nextNum];
            }
            
            mp[currentNum] = currentSequenceLength;
            maxLength = max(maxLength, mp[currentNum]);
        }

        return maxLength;
    }
};