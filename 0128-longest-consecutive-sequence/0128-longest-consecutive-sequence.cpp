class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        if(nums.size() == 0) return 0;

        unordered_set<int> stt;

        for(int i=0;i<nums.size();i++){
            stt.insert(nums[i]);
        }

        for(auto it : stt){

            if(stt.find(it - 1) == stt.end()){
                int count = 1;
                int x = it;
                while(stt.find(x+1) != stt.end()){
                    count += 1;
                    x += 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};