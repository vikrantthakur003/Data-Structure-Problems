class Solution {
public:
    int squareOfNumber(int n){
        int sum = 0;

        while(n > 0){
            int digit = n % 10;
            sum += digit * digit;

            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n == 1){
            return true;
        }

        int slow = n;
        int fast = squareOfNumber(n);

        while(fast != 1 && slow != fast){
            slow = squareOfNumber(slow);
            fast = squareOfNumber(squareOfNumber(fast));
        }

        return fast == 1;
    }
};