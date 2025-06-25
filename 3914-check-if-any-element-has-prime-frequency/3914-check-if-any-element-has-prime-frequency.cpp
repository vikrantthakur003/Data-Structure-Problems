class Solution {
public:
    bool isPrime(int num){
        if(num <= 1){
            return false;
        }
        for(int i=2;i*i<=num;i++){
            if(num % i == 0){
                return false;
            }
        }

        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto itr : mp){
            if(isPrime(itr.second)){
                return true;
            }
        }

        return false;
    }
};