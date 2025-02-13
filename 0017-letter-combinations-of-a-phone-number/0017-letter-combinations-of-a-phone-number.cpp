class Solution {
public:
    string findLetters(char ch){
        switch(ch){
            case '2':
            return "abc";
            case '3':
            return "def";
            case '4':
            return "ghi";
            case '5':
            return "jkl";
            case '6':
            return "mno";
            case '7':
            return "pqrs";
            case '8':
            return "tuv";
            case '9':
            return "wxyz";
            default:
            return "";
        }
        return "";
   }
    void findSubsets(vector<string> &result, int index, string &digits, string temp){
        if(index >= digits.size()){
            result.push_back(temp);
            return;
        }

        string letters = findLetters(digits[index]);
        for(char ch : letters){
            findSubsets(result, index + 1, digits, temp + ch);
        }
       
    }
    vector<string> letterCombinations(string digits){
        if(!digits.size()){
            return {};
        }
        vector<string> result;
        findSubsets(result, 0, digits, "");

        return result;
    }
};