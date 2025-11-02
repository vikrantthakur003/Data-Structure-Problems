class Solution {
public:
    vector<string> result;
    
    void generate(int n, string str, int open, int close){
        if(str.length() >= 2*n){
            result.push_back(str);
            return;
        }

        if(open < n){
            generate(n, str + '(', open + 1, close);
        } 
        if(close < open){
            generate(n,  str + ')', open , close + 1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
    
        generate(n, "", 0, 0);
        return result;
    }
};