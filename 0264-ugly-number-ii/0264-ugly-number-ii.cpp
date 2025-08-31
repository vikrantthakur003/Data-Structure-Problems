class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue<long, vector<long>, greater<long>> minheap;
        unordered_set<long> seen;   // to avoid duplicates
        
        minheap.push(1);
        seen.insert(1);

        int ans = 0;
        while(n != 0){
            long topElement = minheap.top();
            ans = topElement;
            minheap.pop(); // pop smallest value
            
            long twoFactor = topElement * 2;
            long threeFactor = topElement * 3;
            long fiveFactor = topElement * 5;

            // push all factors of top element
             if (!seen.count(twoFactor)) {
                minheap.push(twoFactor);
                seen.insert(twoFactor);
            }
            if (!seen.count(threeFactor)) {
                minheap.push(threeFactor);
                seen.insert(threeFactor);
            }
            if (!seen.count(fiveFactor)) {
                minheap.push(fiveFactor);
                seen.insert(fiveFactor);
            }

            n--;
        }
        return ans;
    }
};