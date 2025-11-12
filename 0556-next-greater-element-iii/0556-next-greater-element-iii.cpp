class Solution {
public:
    const int MOD = 100000007;
    int nextGreaterElement(int n) {
        
        string str = to_string(n);
        
        int size = str.size();
        int pivotIndex = size - 2;

        while(pivotIndex >= 0 && str[pivotIndex] >= str[pivotIndex + 1]){
            pivotIndex--;
        }

        if(pivotIndex >= 0){
            for(int swapIndex = size - 1; swapIndex > pivotIndex; swapIndex--){
                if(str[swapIndex] > str[pivotIndex]){
                    swap(str[pivotIndex], str[swapIndex]);
                    break;
                }
            }

            reverse(str.begin() + pivotIndex + 1, str.end());

            long long ans = stoll(str);
            return ans > INT_MAX ? -1 : ans;
        } 
        
        return -1;
    }
};