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

    vector<string> result;
   void findSubsets(int ind, string str, string &digits){
        if(ind >= digits.size()){
            result.push_back(str);
            return;
        }

        string characters = findLetters(digits[ind]);
        for(char ch : characters){
            findSubsets(ind + 1, str + ch, digits);
        }
   }

    vector<string> letterCombinations(string digits) {
         if(!digits.size()){
            return {};
        }
        findSubsets(0, "", digits);

        return result;
    }
};