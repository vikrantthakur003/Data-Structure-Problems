class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 0;
        for(int i = digits.size() - 1; i>= 0; i--){
            int digitWithOne = digits[i] + carry;

            if(i == digits.size() - 1){
                digitWithOne += 1;
            }

            cout<<digitWithOne<<endl;
            

            if(carry > 0){
                carry--;
            } 

            digits[i] = digitWithOne % 10;
            if(digitWithOne > 9){
                carry += digitWithOne / 10;
            }
            cout<<"carry"<<carry<<endl;
        }

        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};