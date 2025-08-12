class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int maxProfit = 0;
        int buyValue = arr[0];

        for(int i = 1; i<arr.size(); i++){
            int profit = arr[i] - buyValue;

            if(profit > maxProfit){
                maxProfit = profit;
            }

            if(arr[i] < buyValue){
                buyValue = arr[i];
            }
        }

        return maxProfit;
    }
};