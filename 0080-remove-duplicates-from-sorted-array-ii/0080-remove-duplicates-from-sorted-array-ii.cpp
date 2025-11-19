class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        map<int, int> mp;

        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        int k = 0;
        for(auto itr : mp){
            cout<<itr.first <<" "<<itr.second<<endl;
            if(itr.second >= 2 || itr.second == 1){
                int count =  1;
                while(count <= itr.second && count <= 2){
                    nums[k] = itr.first;
                    k++;
                    count++;
                }
            }
        }

        return k;
    }
};