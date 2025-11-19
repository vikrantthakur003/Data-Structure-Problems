class Solution {
public:
    int compress(vector<char>& chars) {

        int count = 1;
        int k = 0;
        chars[k++] = chars[0];

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] != chars[i - 1]) {
                if (count > 1) {
                    string cntString = to_string(count);
                    for (int i = 0; i < cntString.length(); i++) {
                        chars[k++] = cntString[i];
                    }
                }
                count = 1;
                chars[k++] = chars[i];
            } else {
                count++;
            }
        }

        if (count > 1) {
            string cntString = to_string(count);
            for (int i = 0; i < cntString.length(); i++) {
                chars[k++] = cntString[i];
            }
        }

        return k;
    }
};