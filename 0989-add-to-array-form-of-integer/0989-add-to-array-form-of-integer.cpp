class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int n = num.size();
        int i = n - 1;
        int carry = 0;

        vector<int> ans;

        while(i >= 0){
            int lastDigit = k % 10;
            int sum = num[i] + lastDigit + carry;

            ans.push_back(sum % 10);
            carry = sum / 10;
            k = k / 10;

            i--;
        }

        cout<<k<<endl;
        while(k > 0 || carry > 0){
            int lastDigit = k % 10;
            int sum = (lastDigit + carry);

            ans.push_back(sum % 10);

            carry = sum / 10;

            k = k / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};