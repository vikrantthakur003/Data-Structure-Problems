class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;

        string ans = "";
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int n1 = a[i] - '0';
            int n2 = b[j] - '0';

            int sum = n1 + n2 + carry;

            ans += (sum % 2) + '0';
            carry = sum / 2;

            i--;
            j--;
        }

        while (i >= 0) {
            int n1 = a[i] - '0';
            int sum = n1 + carry;

            ans += (sum % 2) + '0';

            carry = sum / 2;
            i--;
        }

        while (j >= 0) {
            int n1 = b[j] - '0';
            int sum = n1 + carry;
            
            ans += (sum % 2) + '0';
            j--;

            carry = sum / 2;
        }

        while(carry > 0){
            ans += carry + '0';
            carry--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};