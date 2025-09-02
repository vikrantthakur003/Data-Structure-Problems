class Solution {
public:
    int getCountLessThan(int x, int row, int col){

        int count = 0;
        for(int i = 1; i<=col; i++){
            int element = x / i;
            if(element == 0){
                break;
            }

            count += min(element, row);
        }

        return count;
    }
    int findKthNumber(int m, int n, int k) {
        
        int low = 1;
        int high = m * n;

        while(low < high){
            int mid = low + (high - low) / 2;

            int count = getCountLessThan(mid, m, n);

            if(count >= k){
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};