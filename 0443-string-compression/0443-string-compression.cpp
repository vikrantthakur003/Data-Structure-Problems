class Solution {
public:
    int compress(vector<char>& chars) {
        
        string str = "";
        int count = 1;
        str += chars[0];

        for(int i = 1; i<chars.size(); i++){
            if(chars[i] != chars[i - 1]) {
                if(count > 1){
                    str += to_string(count);
                }
                count = 1;
                str += chars[i];
            } else {
                count++;
            }
        }

        if(count > 1){
            str += to_string(count);
        }

        int k = 0;
        for(int i = 0; i<str.length(); i++){
            chars[k] = str[i];
            k++;
        }

        return str.length();
    }
};