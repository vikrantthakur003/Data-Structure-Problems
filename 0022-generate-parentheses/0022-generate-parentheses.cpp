class Solution {
public:
    bool validParenthesis(string str){
       int count = 0;
       for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                count++;
            } else{
                count--;
            }

            if(count < 0){
                return false;
            }
       }
        return count == 0;
    }
    void generate(int n, int index, string temp, vector<string> &result){
        if(index >= 2*n){
            if(validParenthesis(temp)){
                result.push_back(temp);
            }
            return;
        }
        temp.push_back('(');
        generate(n, index + 1, temp, result);
        temp.pop_back();

        temp.push_back(')');
        generate(n, index + 1, temp, result);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        generate(n, 0, temp, result);

        return result;
    }
};