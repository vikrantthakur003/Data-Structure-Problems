class Solution {
public:
    int helper(int ind, string &s, long long num, int sign){

        if(ind >= s.length() || !isdigit(s[ind])){
            return (int) (sign * num);
        }

        num = num * 10 + (s[ind] - '0');

        if(num * sign < INT_MIN){
            return INT_MIN;
        }

        if(num * sign > INT_MAX){
            return INT_MAX;
        }

        return helper(ind + 1, s, num, sign);
    }
    int myAtoi(string s) {
        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }

        return helper(i, s, 0, sign);
    }
};