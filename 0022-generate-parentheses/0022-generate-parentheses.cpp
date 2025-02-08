class Solution {
public:
    void findParenthesis(vector<string> &result, string temp, int n, int open, int close){
        if(temp.size() == 2*n){
            result.push_back(temp);
            return;
        }
        if(open < n){
            findParenthesis(result, temp + '(', n, open + 1, close);
        }
        if(close < open){
            findParenthesis(result, temp + ')', n, open, close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        findParenthesis(result, temp, n, 0, 0);

        return result;
    }
};