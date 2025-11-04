class Solution {
public:
    bool isPalindrome(string &str, int start, int end){
        while(start <= end){
            if(str[start] != str[end]){
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
    vector<vector<string>> result;
    void solve(int ind, string &str, vector<string> temp){
        if(ind >= str.length()){
            result.push_back(temp);
            return;
        }

        for(int i = ind; i<str.length(); i++){
            if(isPalindrome(str, ind, i)){
                temp.push_back(str.substr(ind, i - ind + 1));

                solve(i + 1, str, temp);

                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, s, temp);

        return result;
    }
};