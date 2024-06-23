class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxxProfit = INT_MIN;
        int currBuy = prices[0];
        for(int i=1;i<prices.size();i++){
            if(currBuy > prices[i]){
                currBuy = prices[i];
            }
            int currProfit = prices[i] - currBuy;
            if(currProfit > maxxProfit){
                maxxProfit = currProfit;
            }
        }
        if(maxxProfit < 0){
            return 0;
        }
        return maxxProfit;
    }
};