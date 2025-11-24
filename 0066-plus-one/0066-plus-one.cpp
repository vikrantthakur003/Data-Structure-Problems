class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        for(int i = digits.size() - 1; i>= 0; i--){
            int digitWithOne = digits[i] + carry;

            digits[i] = digitWithOne % 10;
            carry = digitWithOne / 10;

            if(carry == 0){ // no need to traverse digit
                break;
            }
        }

        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};